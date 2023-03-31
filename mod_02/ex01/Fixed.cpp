/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/31 16:01:05 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0){
    std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const int fp){
    setRawBits(fp << _bitsFract);
    std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const float fp) {
    int intPart = int(fp);
    float fractPart = fp - intPart;
    _fixedPoint = int(roundf((fractPart * (1 << _bitsFract)) + (intPart << _bitsFract)));
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float fp) {
   
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy construtor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

void    Fixed::setRawBits(int const new_val){
    Fixed::_fixedPoint = new_val;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPoint = other.getRawBits();
    return (*this);
}
