/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:45:59 by tristan           #+#    #+#             */
/*   Updated: 2023/05/31 12:44:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

Converter::Converter(): _base("0"), _type("def"), _precision(0), _print_flag(0), _intConvert(0), _doubleConvert(0),
	_floatConvert(0), _charConvert(0){convert();}

Converter::Converter(std::string base): _base(base), _type("def"), _precision(0), _print_flag(0), _intConvert(0), _doubleConvert(0),
	_floatConvert(0), _charConvert(0){convert();}

Converter::Converter(const Converter& new_object): _base(new_object._base){*this = new_object; convert();}

Converter::~Converter(){}

const char* Converter::WrongInput::what() const throw() {return ("Invalid argument");}

std::string Converter::get_base(void) const {return(this->_base);}
char		Converter::get_charConvert(void) const {return(this->_charConvert);}
int			Converter::get_intConvert(void) const {return(this->_intConvert);}
double		Converter::get_doubleConvert(void) const {return(this->_doubleConvert);}
float		Converter::get_floatConvert(void) const {return(this->_floatConvert);}
int			Converter::get_print_flag(void) const {return(this->_print_flag);}
int			Converter::get_precision(void) const {return(this->_precision);}

void		Converter::set_precision(int new_value) {this->_precision = new_value;}

int	Converter::parse_string(){
	int i = 0;
	int flag = 0;

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
	if(parse_string() != 0){
		throw WrongInput();
		return ;
	}
	if (_base.size() == 1 && !isdigit(_base[0])){
		_type = "char";
		_charConvert = _base[0];
		from_char();
	}
	else if (_base.back() == 'f'){
		_base.pop_back();
		if (is_all_digits_and_dot(_base) == 0){
			_type = "float";
			char* end;
			try{
				_floatConvert = std::strtof(_base.c_str(), &end);
			}
			catch(const std::exception& e){
				throw e.what();
				return ;
			}
			from_float();
		}
		else
			throw WrongInput();
	}
	else if (is_all_digits_and_dot(_base) == 0){
		_type = "double";
		try{
			char* end;
			_doubleConvert = std::strtod(_base.c_str(), &end);
		}
		catch(const std::exception& e){
			throw e.what();
			return ;
		}
		from_double();
	}
	else if (is_all_digits_and_dot(_base) == 2){
		_type = "int";
		try{
			char* end;
			_intConvert = std::strtol(_base.c_str(), &end, 10);
		}
		catch(const std::exception& e){
			throw e.what();
			return ;
		}
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
	else if (convert.get_print_flag() == 1)
		output << "Char: " << "Non printable" << std::endl;

	output << "Int: " << convert.get_intConvert() << std::endl;

	if (convert.get_precision() == 0){
		output << "Float: " << std::fixed << std::setprecision(1) << convert.get_floatConvert()<< "f" << std::endl
		<< "Double: " << std::fixed << std::setprecision(1) << convert.get_doubleConvert() << std::endl;
	}
	else{
		output<< "Float: " << std::fixed << std::setprecision(convert.get_precision()) << convert.get_floatConvert()<< "f" << std::endl
		<< "Double: " << std::fixed << std::setprecision(convert.get_precision()) << convert.get_doubleConvert() << std::endl;
	}
	return (output);
}
