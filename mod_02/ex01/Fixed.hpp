/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/05 14:29:18 by tbeaudoi         ###   ########.fr       */
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

        float           toFloat(void) const;
        int             toInt(void) const;

        Fixed&          operator=(const Fixed& ohter);
        
        int             getRawBits(void) const;
		void            setRawBits(int const raw);
        
    private:
        int                 _fixedPoint;
        static const int    _bitsFract = 8;

};

std::ostream&   operator<<(std::ostream& output, const Fixed& fixed);

#endif