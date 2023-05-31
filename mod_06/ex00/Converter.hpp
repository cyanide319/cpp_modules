/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:25:12 by tristan           #+#    #+#             */
/*   Updated: 2023/05/31 14:51:19 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<iostream>
#include<stdexcept>
#include<limits>

class Converter{
	public:
		Converter();
		Converter(std::string base);
		Converter(const Converter& new_object);
		~Converter();

		void	convert();
		int		parse_string();
		int		is_all_digits_and_dot(std::string& str);
		void	find_precision(std::string& str);

		void	from_char();
		void	from_int();
		void	from_double();
		void	from_float();

		std::string	get_base(void) const;
		std::string get_type(void) const;
		char		get_charConvert(void) const;
		int			get_intConvert(void) const;
		double		get_doubleConvert(void) const;
		float		get_floatConvert(void) const;
		int			get_print_flag(void) const;
		int			get_impossible_flag(void) const;
		int			get_precision(void) const;

		void		set_precision(int new_value);

		class WrongInput: public std::exception{
			public:
				const char* what() const throw();
		};
		class Overflow: public std::exception{
			public:
				const char* what() const throw();
		};
		class Invalid: public std::exception{
			public:
				const char* what() const throw();
		};

		Converter& operator=(const Converter& other);
	private:
		std::string			_base;
		std::string			_type;
		int					_impossible_flag;
		int					_precision;
		int					_print_flag;
		int					_intConvert;
		double				_doubleConvert;
		float				_floatConvert;
		char				_charConvert;
};

std::ostream& operator<<(std::ostream& output, const Converter& convert);

#endif