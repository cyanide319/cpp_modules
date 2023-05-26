/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:45:59 by tristan           #+#    #+#             */
/*   Updated: 2023/05/25 16:52:47 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

Converter::Converter(){}

Converter::Converter(std::string base): _base(base){}

Converter::Converter(const Converter& new_object): _base(new_object._base){*this = new_object;}

Converter::~Converter(){}

const char* Converter::TooManyCharException::what() const throw() {return ("Invalid argument\n");}

std::string Converter::get_base(void) const {return(this->_base);}
char		Converter::get_charConvert(void) const {return(this->_charConvert);}
int			Converter::get_intConvert(void) const {return(this->_intConvert);}
double		Converter::get_doubleConvert(void) const {return(this->_doubleConvert);}
float		Converter::get_floatConvert(void) const {return(this->_floatConvert);}

int	Converter::parse_string(){
	int i = 0;
	int flag = 0;

	while(_base[i]){
		if (_base[i] >= 'a' && _base[i] >= 'z')
			flag++;
		i++;
	}
	if (flag >= 2)
		return(1);
	return(0);
}

void	Converter::convert(){
	if(parse_string() != 0)
		throw TooManyCharException();
	try{
		const char* basestr = _base.c_str();
		_charConvert = basestr[0];
		_intConvert = std::atoi(basestr);
		_floatConvert = std::atof(basestr);
		_doubleConvert = std::strtod(basestr, NULL);		
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	
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
	output << "Char :" << convert.get_charConvert() << std::endl
	<< "Int :" << convert.get_intConvert() << std::endl
	<< "Float :" << convert.get_floatConvert() << std::endl
	<< "Double :" << convert.get_doubleConvert() << std::endl;
	return (output);
}