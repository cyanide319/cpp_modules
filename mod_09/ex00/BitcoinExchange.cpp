/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:49:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/10 14:43:05 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path): _line(0){
	parsing(path);
}

BitcoinExchange::~BitcoinExchange(){}

const char* BitcoinExchange::EmptyFd::what() const throw(){return ("Empty or missing fd");};
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

  #include <unistd.h>

int	BitcoinExchange::parse_date(std::string str){
	size_t end = str.find_first_of(" |");
	std::vector<std::string> temp;
	std::string				substr;

	if (end != std::string::npos){
		substr = str.substr(0, end);
		temp = split_vectors(substr, '-');
		try{
			std::istringstream year(temp[0]);
			std::istringstream month(temp[1]);
			std::istringstream day(temp[2]);
			year >> _year;
			if (_year <= 0){
				throw BadFormat();
				return (1);
			}
			month >> _month;
			if (_month <= 0){
				throw BadFormat();
				return (1);
			}
			day >> _day;
			if (_day <= 0){
				throw BadFormat();
				return (1);
			}
			std::cout << _year << std::endl;
			std::cout << _month << std::endl;
			std::cout << _day << std::endl;
			sleep(1);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
			return (1);
		}
		return (0);
	}
	else
		throw BadFormat();
	return (1);
}

int	BitcoinExchange::parsing(std::string path){
	std::ifstream infile(path);
	if (!infile){
		throw EmptyFd();
		return (1);
	}

	std::string buffer;



	if (infile.is_open()){
		while(getline(infile, buffer)){
			size_t i = buffer.find_first_of("2");
			if (i != std::string::npos){
				if (parse_date(buffer) == 1)
					return (1);
			}
			_line++;
		}
	}
	return (0);
}