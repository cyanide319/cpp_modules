/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/16 15:48:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_size(0){}

PmergeMe::PmergeMe(std::string input):_size(0){
	_vector.clear();
	_list.clear();
	parse_input(input);
}

PmergeMe::PmergeMe(const PmergeMe& new_object):_size(0){*this = new_object;}

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

void	PmergeMe::print_vector(){
	for(size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::print_list(){
	std::list<int>::iterator it;
	for(it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
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
		_list.push_back(_temp);
		_size++;
	}

	return (0);
}

// template <typename T>
// int	PmergeMe::sort_algo(T& input){
	
// }


PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if(this != &other){
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return(*this);
}