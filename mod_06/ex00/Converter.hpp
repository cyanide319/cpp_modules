/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:25:12 by tristan           #+#    #+#             */
/*   Updated: 2023/05/26 12:26:12 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include<cstdlib>
#include<string>
#include<iostream>
#include<stdexcept>

class Converter{
	public:
		Converter();
		Converter(std::string base);
		Converter(const Converter& new_object);
		~Converter();

		void	convert();
		int		parse_string();

		std::string	get_base(void) const;
		char		get_charConvert(void) const;
		int			get_intConvert(void) const;
		double		get_doubleConvert(void) const;
		float		get_floatConvert(void) const;

		class TooManyCharException: public std::exception{
			public:
				const char* what() const throw();
		};

		Converter& operator=(const Converter& other);
	private:
		const std::string	_base;
		int					_intConvert;
		double				_doubleConvert;
		float				_floatConvert;
		char				_charConvert;
};

std::ostream& operator<<(std::ostream& output, const Converter& convert);

#endif