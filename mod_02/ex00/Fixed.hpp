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