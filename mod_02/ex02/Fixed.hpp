/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/07 14:22:56 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_H
#define FIXED_H

#pragma once

#include<iostream>
#include<ostream>
#include<cmath>

class Fixed{
    public:
        Fixed();
        Fixed(const float fp);
        Fixed(const int fp);
        Fixed(const Fixed& new_object);
        ~Fixed();

        float           	toFloat(void) const;
        int             	toInt(void) const;

        Fixed&          	operator=(const Fixed& ohter);
        bool            	operator>(const Fixed& other);
        bool            	operator<(const Fixed& other);
        bool            	operator>=(const Fixed& other);
        bool            	operator<=(const Fixed& other);
        bool            	operator==(const Fixed& other);
        bool            	operator!=(const Fixed& other);
        Fixed           	operator*(const Fixed& other);
        Fixed           	operator/(const Fixed& other);
        Fixed           	operator+(const Fixed& other);
        Fixed           	operator-(const Fixed& other);
        Fixed           	operator--(void);
        Fixed           	operator++(void);
        Fixed				operator--(int);
        Fixed				operator++(int);

        static Fixed&		min(Fixed& left_side, Fixed& right_side);
        static Fixed&		max(Fixed& left_side, Fixed& right_side);
        const static Fixed&	min(const Fixed& left_side, const Fixed& right_side);
        const static Fixed&	max(const Fixed& left_side, const Fixed& right_side);
        
        int             	getRawBits(void) const;
		void            	setRawBits(int const raw);
        
    private:
        int                 _fixedPoint;
        static const int    _bitsFract = 8;

};

std::ostream&   operator<<(std::ostream& output, const Fixed& fixed);

#endif