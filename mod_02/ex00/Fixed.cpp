/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/31 13:09:56 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point(0){
    std::cout << "Default construtor called" << std::endl;
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
    return (_fixed_point);
}

void    Fixed::setRawBits(int const new_val){
    Fixed::_fixed_point = new_val;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixed_point = other.getRawBits();
    return (*this);
}
