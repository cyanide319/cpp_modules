/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:49:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/07 14:57:20 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path): _line(0){
	parsing(path);
}

BitcoinExchange::~BitcoinExchange(){}

const char* BitcoinExchange::EmptyFd::what() const throw(){return ("Empty or missing fd.");};
const char* BitcoinExchange::BadFormat::what() const throw(){return ("Bad format");};

std::vector<std::string>	BitcoinExchange::split_vectors(std::string str, char delimiter){
	std::vector<std::string>	ret;
	std::stringstream 			ss(str);
	std::string 				token;

	while(std::getline(ss, token, delimiter)){
		ret.push_back(token);
	}

	return (ret);
}

void	parse_date(std::string str){
	size_t end = str.find_first_of(" |");
	if (end != std::string::npos){
		int i = 0;
	}
	else
		throw BadFormat();
}

void	BitcoinExchange::parsing(std::string path){
	std::ifstream infile(path);
	if (!infile){
		throw EmptyFd();
		return ;
	}

	std::string buffer;



	if (infile.is_open()){
		while(getline(infile, buffer)){
			size_t i = buffer.find_first_of("2");
			if (i != std::string::npos){
				
			}
			_line++;
			_bad_format_msg = "Bad format on line: " + _line;
		}
	}
}