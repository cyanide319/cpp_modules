#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point(0){
    std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const Fixed& new_object){
    std::cout << "Copy construtor called" << std::endl;
    this->_fixed_point = new_object._fixed_point;
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const{
    return (_fixed_point);
}

void    Fixed::setRawBits(int const new_val){
    Fixed::_fixed_point = new_val;
}

Fixed& Fixed::operator=(const Fixed& ohter){
    
}