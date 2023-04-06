/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/05 18:53:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

//Construtors

Fixed::Fixed(): _fixedPoint(0){
    std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const int fp){
	setRawBits(fp << _bitsFract);
    std::cout << "Int construtor called" << std::endl;
}

Fixed::Fixed(const float fp) {
    int intPart = int(fp);
    float fractPart = fp - intPart;
    setRawBits(int(roundf((fractPart * (1 << _bitsFract)) + (intPart << _bitsFract))));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy construtor called" << std::endl;
    *this = other;
}

//Destructors

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

//Getters

int Fixed::getRawBits(void) const{
    return (this->_fixedPoint);
}

//Setters

void    Fixed::setRawBits(int const new_val){
    Fixed::_fixedPoint = new_val;
}

//Functions

float   Fixed::toFloat(void) const{
    return (float(this->_fixedPoint) / (1 << _bitsFract));
}

int Fixed::toInt(void) const{
    return (this->_fixedPoint >> _bitsFract);
}

//OPERATORS OVERLOADS--------------------------------------------------
//Copy Assigment Operator

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPoint = other.getRawBits();
    return (*this);
}

// Arithmetic Operators

bool Fixed::operator>(const Fixed& other){
    if (this->_fixedPoint > other._fixedPoint)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other){
    if (this->_fixedPoint < other._fixedPoint)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other){
    if (this->_fixedPoint >= other._fixedPoint)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other){
    if (this->_fixedPoint <= other._fixedPoint)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other){
    if (this->_fixedPoint == other._fixedPoint)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other){
    if (this->_fixedPoint != other._fixedPoint)
        return (true);
    return (false);
}

Fixed Fixed::operator*(const Fixed& other) {
    Fixed result;
    result.setRawBits((this->_fixedPoint * other.getRawBits()) >> this->_bitsFract);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) {
    Fixed result;
    result.setRawBits((this->getRawBits()) << this->_bitsFract / other.getRawBits());
    return (result);
}

Fixed Fixed::operator+(const Fixed& other){
    Fixed result;
    result.setRawBits((this->getRawBits()) + (other.getRawBits()));
    return (result);
}

Fixed Fixed::operator-(const Fixed& other){
    Fixed result;
    result.setRawBits((this->getRawBits()) - (other.getRawBits()));
    return (result);
}

Fixed   Fixed::operator--(void){
    _fixedPoint--;
    return (*this);
}

Fixed   Fixed::operator--(int){
    Fixed temp(*this);
    _fixedPoint--;
    return (temp);
}

Fixed   Fixed::operator++(void){
    _fixedPoint++;
    return (*this);
}

Fixed  Fixed::operator++(int){
    Fixed temp(*this);
    _fixedPoint++;
    return (temp);
}

//Stream Operator

std::ostream&	operator<<(std::ostream& output, const Fixed& fixed){
	output << fixed.toFloat();
	return (output);
}

//Overloaded min/max functions

Fixed&   Fixed::min(Fixed& left_side, Fixed& right_side){
    if(left_side._fixedPoint < right_side._fixedPoint)
        return (left_side);
    return (right_side);
}

const Fixed&   Fixed::min(const Fixed& left_side, const Fixed& right_side){
    if(left_side._fixedPoint < right_side._fixedPoint)
        return (left_side);
    return (right_side);
}

Fixed&   Fixed::max(Fixed& left_side, Fixed& right_side){
    if(left_side._fixedPoint > right_side._fixedPoint)
        return (left_side);
    return (right_side);
}

const Fixed&   Fixed::max(const Fixed& left_side, const Fixed& right_side){
    if(left_side._fixedPoint > right_side._fixedPoint)
        return (left_side);
    return (right_side);
}
