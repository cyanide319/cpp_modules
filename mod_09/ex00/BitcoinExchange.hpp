/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:13:07 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/10 14:41:57 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


class BitcoinExchange{
	public:
		BitcoinExchange(std::string path);
		~BitcoinExchange();

		int							parsing(std::string path);
		int							parse_date(std::string str);
		std::vector<std::string>	split_vectors(std::string str, char delimiter);

		class EmptyFd: public std::exception{
			public:
				const char* what() const throw();
		};
		class BadFormat: public std::exception{
			public:
				const char* what() const throw();
		};

	private:
		std::map<int[3], float>	_data;
		size_t					_line;
		int						_year;
		int						_month;
		int						_day;
};

#endif