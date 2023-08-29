/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:49:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/29 13:42:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path): _line(0){
	parsing_database("./data.csv");
	parsing_input(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& new_object){*this = new_object;}

BitcoinExchange::~BitcoinExchange(){}

const char* BitcoinExchange::EmptyFd::what() const throw(){return ("Error: Empty or missing fd");};
const char* BitcoinExchange::BadFormat::what() const throw(){return ("Error: Bad format");};

bool BitcoinExchange::is_string_digit(const std::string& str){
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it) && *it != '.'&& *it != '-') {
            return false;
        }
    }
    return true;
}

int BitcoinExchange::parse_price(std::string str){
	size_t 		start = str.find_first_of(",");
	std::stringstream	line;
	line << _line;

	if (start != std::string::npos){
		_price = 0;
		std::string	substr = str.substr(start + 1, str.size());
		if (is_string_digit(substr) == false){
			std::string error = "Error: Not a digit on line: " + line.str();
			throw std::runtime_error(error);
			}
		char* end;
		_price = std::strtod(substr.c_str(), &end);
		if (_price < 0.00){
			std::string error = "Error: Not a positive number on line: " + line.str();
			throw std::runtime_error(error);
		}
		if (_price >= INT_MAX){
			std::string error = "Error: Number too large on line: " + line.str();
			throw std::runtime_error(error);
		}
		return (0);
	}
	else
		throw BadFormat();
	return (1);
}

int BitcoinExchange::parse_price_input(std::string str){
	size_t 		start = str.find_first_of("|");
	std::stringstream	line;
	line << _line;

	if (start != std::string::npos){
		_price = 0;
		std::string	substr = str.substr(start + 2, str.size());
		if (is_string_digit(substr) == false){
			std::string error = "Error: Not a digit on line: " + line.str();
			std::cerr << error << std::endl;
			return (1);
			}
		char* end;
		_price = std::strtod(substr.c_str(), &end);
		if (_price < 0.00){
			std::string error = "Error: Not a positive number on line: " + line.str();
			std::cerr << error << std::endl;
			return (1);
		}
		if (_price >= INT_MAX){
			std::string error = "Error: Number too large on line: " + line.str();
			std::cerr << error << std::endl;
			return (1);
		}
		return (0);
	}
	else
		throw BadFormat();
	return (1);
}

int	BitcoinExchange::parse_date(std::string str){
	size_t 				end = str.find_first_of(",");
	std::string			temp[3];
	std::stringstream	line;
	line << _line;

	if (end < 10){
		std::string error = "Error: Date is wrong in database on line: " + line.str();
		throw std::runtime_error(error);
		return (1);
	}
		
	if (end != std::string::npos){
		_year = 0;
		_month = 0;
		_day = 0;
		std::string		substr = str.substr(0, end);
		std::stringstream 			ss(substr);
		std::string 				token;
		int							i = 0;

		while(std::getline(ss, token, '-')){
			temp[i] += token;
			i++;
			if (i > 2)
				break ;
		}
		if (is_string_digit(temp[0]) == false || is_string_digit(temp[1]) == false
			|| is_string_digit(temp[2]) == false){
			std::string error = "Error: Missing a value in database on line: " + line.str();
			throw std::runtime_error(error);
		}
		std::istringstream year(temp[0]);
		std::istringstream month(temp[1]);
		std::istringstream day(temp[2]);
		year >> _year;
		month >> _month;
		day >> _day;
		if ((_year < 2009 || _year > 2023) || (_month < 1 || _month > 12) || (_day < 1 || _day > 31)){
			std::string error = "Error: Date is wrong in database on line: " + line.str();
			throw std::runtime_error(error);
			return (1);
		}
		if (_month == 4 || _month == 6 || _month == 9 || _month == 11){
			if (_day > 30){
				std::string error = "Error: Date is wrong in database on line: " + line.str();
				throw std::runtime_error(error);
				return (1);
				}
		}
		else if (_month == 2){
			if (_day > 29){
				std::string error = "Error: Date is wrong in database on line: " + line.str();
				throw std::runtime_error(error);
				return (1);
				}
		}
		_key = substr;
		return (0);
	}
	else
		throw BadFormat();
	return (1);
}

int	BitcoinExchange::parse_date_input(std::string str){
	size_t 				end = str.find_first_of(" |");
	std::string			temp[3];
	std::stringstream	line;
	line << _line;

	if (end < 10){
		std::string error = "Error: Date is wrong on line: " + line.str();
		std::cerr << error << std::endl;
		return (1);
	}

	if (end != std::string::npos){
		_year = 0;
		_month = 0;
		_day = 0;
		std::string		substr = str.substr(0, end);
		std::stringstream 			ss(substr);
		std::string 				token;
		int							i = 0;

		while(std::getline(ss, token, '-')){
			temp[i] += token;
			i++;
			if (i > 2)
				break ;
		}
		if (is_string_digit(temp[0]) == false || is_string_digit(temp[1]) == false
			|| is_string_digit(temp[2]) == false){
			std::string error = "Error: Missing a value on line: " + line.str();
			std::cerr << error << std::endl;
			return (1);
		}
		std::istringstream year(temp[0]);
		std::istringstream month(temp[1]);
		std::istringstream day(temp[2]);
		year >> _year;
		month >> _month;
		day >> _day;
		if ((_year < 2009 || _year > 2023) || (_month < 1 || _month > 12) || (_day < 1 || _day > 31)){
			std::string error = "Error: Date is wrong on line: " + line.str();
			std::cerr << error << std::endl;
			return (1);
		}
		if (_month == 4 || _month == 6 || _month == 9 || _month == 11){
			if (_day > 30){
				std::string error = "Error: Date is wrong on line: " + line.str();
				std::cerr << error << std::endl;
				return (1);
				}
		}
		else if (_month == 2){
			if (_day > 29){
				std::string error = "Error: Date is wrong on line: " + line.str();
				std::cerr << error << std::endl;
				return (1);
				}
		}
		_key = substr;
		return (0);
	}
	else
		throw BadFormat();
	return (1);
}

int	BitcoinExchange::parsing_database(std::string path){
	_line = 2;
	std::ifstream infile(path);
	if (!infile){
		throw EmptyFd();
		return (1);
	}

	std::string buffer;


	getline(infile, buffer);
	if (infile.is_open()){
		while(getline(infile, buffer)){
			size_t i = buffer.find_first_of(",");
			if (i != std::string::npos && buffer[0] == '2'){
				if (parse_date(buffer) == 1)
					return (1);
				if (parse_price(buffer) == 1)
					return (1);
				_data[_key] = _price;
			}
			else{
				std::stringstream	line;
				line << _line;
				std::string error = "Error: Bad format on line: " + line.str();
				throw std::runtime_error(error);
			}
			_line++;
		}
	}
	return (0);
}

int	BitcoinExchange::check_database(){
	double ret = 0;
	std::map<std::string, double>::const_iterator iter;
    for (iter = _data.begin(); iter != _data.end(); ++iter) {
        if (iter->first == _key){
			ret = iter->second * _price;
			std::cout << _key << " => " << _price << " = " << ret << std::endl;
			return (0);
		}
		if (iter->first > _key){
			iter --;
			ret = iter->second * _price;
			std::cout << _key << " => " << _price << " = " << ret << std::endl;
			return (0);
		}
    }
	return (1);
}

int	BitcoinExchange::parsing_input(std::string path){
	_line = 2;
	std::ifstream infile(path);
	if (!infile){
		throw EmptyFd();
		return (1);
	}

	std::string buffer;


	getline(infile, buffer);
	if (infile.is_open()){
		while(getline(infile, buffer)){
			size_t i = buffer.find_first_of("|");
			if (i != std::string::npos && buffer[0] == '2'){
				if (parse_date_input(buffer) == 0)
					if (parse_price_input(buffer) == 0)
						if (check_database() == 1)
							std::cerr << "Error: Not found in the database" << std::endl;
			}
			else{
				std::stringstream	line;
				line << _line;
				std::string error = "Error: Wrong format on line: " + line.str();
				std::cerr << error << std::endl;
			}
			_line++;
		}
	}
	return (0);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if(this != &other){
		this->_data = other._data;
		this->_key = other._key;
		this->_line = other._line;
		this->_year = other._year;
		this->_month = other._month;
		this->_day = other._day;
		this->_price = other._price;
	}
	return(*this);
}
