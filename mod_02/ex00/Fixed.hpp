/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:47:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/31 13:03:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_H
#define FIXED_H

#pragma once

#include<iostream>

class Fixed{
    public:
        Fixed();
        Fixed(const Fixed& new_object);
        ~Fixed();
        
        Fixed& operator=(const Fixed& ohter);
        int     getRawBits(void) const;
		void    setRawBits(int const raw);
    private:
        int                 _fixed_point;
        static const int    _bits_fract = 8;

};

#endif