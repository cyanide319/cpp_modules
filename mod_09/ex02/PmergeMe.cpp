/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/13 15:20:14 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string input){
	_vector.clear();
	_deque.clear();
	parse_input(input);
}

PmergeMe::PmergeMe(const PmergeMe& new_object){*this = new_object;}
PmergeMe::~PmergeMe(){}

std::vector<std::string>	PmergeMe::split_vectors(std::string str, char delimiter){
	std::vector<std::string>	ret;
	std::stringstream ss(str);
	std::string token;

	while(std::getline(ss, token, delimiter))
		ret.push_back(token);
	return (ret);
}

bool PmergeMe::is_string_digit(const std::string& str){
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

bool PmergeMe::is_string_int(const std::string& str){
	std::istringstream value(str);
	int temp;

	_temp = 0;
	value >> temp;
	if (temp >= INT_MAX) {
            return false;
    }
	_temp = temp;
    return true;
}

int PmergeMe::parse_input(std::string input){
	std::vector<std::string> temp = split_vectors(input, ' ');
	
	for (size_t i = 0; i < temp.size(); i++){
		if (is_string_digit(temp[i]) == false)
			throw std::runtime_error("Error: Bad input");
	}
	for (size_t i = 0; i < temp.size(); i++){
		if (is_string_int(temp[i]) == false)
			throw std::runtime_error("Error: Bad input 2");
		_vector.push_back(_temp);
		_deque.push_back(_temp);
	}
	
	for(size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	for(size_t i = 0; i < _deque.size(); i++)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;
	return (0);
	// parse_vector(temp);
	// parse_deque(temp);
}

template <typename T>
int	PmergeMe::sort_algo(T& input){
	
}

// int	PmergeMe::parse_vector(std::vector<std::string> input){
// }
// int	PmergeMe::parse_deque(std::vector<std::string> input){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if(this != &other){
		this->_deque = other._deque;
		this->_vector = other._vector;
	}
	return(*this);
}