/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:45:59 by tristan           #+#    #+#             */
/*   Updated: 2023/05/31 14:59:35 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

Converter::Converter(): _base("0"), _type("def"), _impossible_flag(0), _precision(0), _print_flag(0), _intConvert(0), _doubleConvert(0),
	_floatConvert(0), _charConvert(0){convert();}

Converter::Converter(std::string base): _base(base), _type("def"), _impossible_flag(0), _precision(0), _print_flag(0), _intConvert(0), _doubleConvert(0),
	_floatConvert(0), _charConvert(0){convert();}

Converter::Converter(const Converter& new_object): _base(new_object._base){*this = new_object; convert();}

Converter::~Converter(){}

const char* Converter::WrongInput::what() const throw() {return ("Invalid argument");}
const char* Converter::Overflow::what() const throw() {return ("Overflow");}
const char* Converter::Invalid::what() const throw() {return ("Invalid conversion");}

std::string Converter::get_base(void) const {return(this->_base);}
std::string Converter::get_type(void) const {return(this->_type);}
char		Converter::get_charConvert(void) const {return(this->_charConvert);}
int			Converter::get_intConvert(void) const {return(this->_intConvert);}
double		Converter::get_doubleConvert(void) const {return(this->_doubleConvert);}
float		Converter::get_floatConvert(void) const {return(this->_floatConvert);}
int			Converter::get_print_flag(void) const {return(this->_print_flag);}
int			Converter::get_impossible_flag(void) const {return(this->_impossible_flag);}
int			Converter::get_precision(void) const {return(this->_precision);}

void		Converter::set_precision(int new_value) {this->_precision = new_value;}

int	Converter::parse_string(){
	int i = 0;
	int flag = 0;

	if (_base == "-inff" || _base == "+inff" || _base == "nanf" || _base == "-inf" || _base == "+inf" || _base == "nan"){
		_impossible_flag = 1;
		return (0);
	}
	while(_base[i]){
		if ((_base[i] >= 'a' && _base[i] >= 'z') || (_base[i] >= 'A' && _base[i] >= 'B'))
			flag++;
		i++;
	}
	if (flag >= 2)
		return(1);
	return(0);
}

void	Converter::find_precision(std::string& str){
	int flag = 0;
	for (std::string::size_type i = 0; i < str.length(); ++i){
		if (flag == 1)
			_precision++;
		if (str[i] == '.')
			flag = 1;
	}
}

int	Converter::is_all_digits_and_dot(std::string& str){
	int dot = 0;
	for (std::string::size_type i = 0; i < str.length(); ++i){
		if (str[i] == '.')
			dot++;
		if ((!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-') || dot > 1)
			return (1);
	}
	if (dot < 1)
		return (2);
	return (0);
}

void	Converter::from_char(){
	if (!isprint(_charConvert))
		_print_flag = 1;
	_floatConvert = static_cast<float>(_charConvert);
	_doubleConvert = static_cast<double>(_charConvert);
	_intConvert = static_cast<int>(_charConvert);
}

void	Converter::from_double(){
	if (!isprint(_doubleConvert))
		_print_flag = 1;
	_charConvert = static_cast<char>(_doubleConvert);
	_floatConvert = static_cast<float>(_doubleConvert);
	_intConvert = static_cast<int>(_doubleConvert);
}

void	Converter::from_float(){
	if (!isprint(_floatConvert))
		_print_flag = 1;
	_charConvert = static_cast<char>(_floatConvert);
	_doubleConvert = static_cast<double>(_floatConvert);
	_intConvert = static_cast<int>(_floatConvert);
}

void	Converter::from_int(){
	if (!isprint(_intConvert))
		_print_flag = 1;
	_charConvert = static_cast<char>(_intConvert);
	_floatConvert = static_cast<float>(_intConvert);
	_doubleConvert = static_cast<double>(_intConvert);
}



void	Converter::convert(){
	if(parse_string() != 0)
		throw WrongInput();
	if (_base.size() == 1 && !isdigit(_base[0])){
		_type = "char";
		_charConvert = _base[0];
		from_char();
	}
	else if (is_all_digits_and_dot(_base) == 0 || _base == "-inf" || _base == "+inf" || _base == "nan"){
		_type = "double";
		char* end;
		_doubleConvert = std::strtod(_base.c_str(), &end);
		if (errno == ERANGE)
			throw Overflow();
		else if (end == _base.c_str())
			throw Invalid();
		from_double();
	}
	else if (_impossible_flag == 1){
		_type = "float";
		char* end;
		_floatConvert = std::strtof(_base.c_str(), &end);
		if ((_floatConvert == HUGE_VALF || _floatConvert == -HUGE_VALF) && errno == ERANGE)
			throw Overflow();
		from_float();
	}
	else if (_base.back() == 'f'){
		_base.pop_back();
		if (is_all_digits_and_dot(_base) == 0){
			_type = "float";
			char* end;
			_floatConvert = std::strtof(_base.c_str(), &end);
			if ((_floatConvert == HUGE_VALF || _floatConvert == -HUGE_VALF) && errno == ERANGE)
				throw Overflow();
			from_float();
		}
		else
			throw WrongInput();
	}
	else if (is_all_digits_and_dot(_base) == 2){
		_type = "int";
		char* end;
		long temp;
		temp = std::strtol(_base.c_str(), &end, 10);
		if (errno == ERANGE || temp > INT_MAX || temp < INT_MIN)
			throw Overflow();
		else if (end == _base.c_str())
			throw Invalid();
		_intConvert = temp;
		from_int();
	}
	else
		throw WrongInput();
	find_precision(_base);
}

Converter& Converter::operator=(const Converter& other){
	if(this != &other){
		this->_charConvert = other._charConvert;
		this->_doubleConvert = other._doubleConvert;
		this->_floatConvert = other._floatConvert;
		this->_intConvert = other._intConvert;
	}
	return(*this);
}

std::ostream& operator<<(std::ostream& output, const Converter& convert){
	if (convert.get_print_flag() == 0)
		output << "Char: " << convert.get_charConvert() << std::endl;
	else if (convert.get_print_flag() == 1){
		if (convert.get_impossible_flag() == 0)
			output << "Char: " << "Non printable" << std::endl;
		else if (convert.get_impossible_flag() == 1)
			output << "Char: " << "Impossible" << std::endl;
	}
	
	if (convert.get_impossible_flag() == 1 || (convert.get_intConvert() <= INT_MIN && convert.get_type() != "int"))
		output << "Int: " << "Impossible" << std::endl;
	else if (convert.get_impossible_flag() == 0)
		output << "Int: " << convert.get_intConvert() << std::endl;

	if (convert.get_precision() == 0){
		output << "Float: " << std::fixed << std::setprecision(1) << convert.get_floatConvert()<< "f" << std::endl
		<< "Double: " << std::fixed << std::setprecision(1) << convert.get_doubleConvert() << std::endl;
	}
	else if(convert.get_precision() < 6){
		output<< "Float: " << std::fixed << std::setprecision(convert.get_precision()) << convert.get_floatConvert()<< "f" << std::endl
		<< "Double: " << std::fixed << std::setprecision(convert.get_precision()) << convert.get_doubleConvert() << std::endl;
	}
	else{
		output<< "Float: " << std::scientific << convert.get_floatConvert()<< "f" << std::endl
		<< "Double: " << std::scientific << convert.get_doubleConvert() << std::endl;
	}
	return (output);
}
