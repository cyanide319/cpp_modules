/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:13:07 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/12 13:29:13 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


class BitcoinExchange{
	public:
		BitcoinExchange(std::string path);
		~BitcoinExchange();

		int				parsing_database(std::string path);
		int				parsing_input(std::string path);
		int				check_database();
		int				parse_date(std::string str);
		int				parse_date_input(std::string str);
		int				parse_price(std::string str);
		int				parse_price_input(std::string str);
		bool 			is_string_digit(const std::string& str);
		

		class EmptyFd: public std::exception{
			public:
				const char* what() const throw();
		};
		class BadFormat: public std::exception{
			public:
				const char* what() const throw();
		};
		
	private:
		std::map<std::string, double>	_data;
		std::string						_key;
		int								_line;
		int								_year;
		int								_month;
		int								_day;
		double							_price;
};

#endif