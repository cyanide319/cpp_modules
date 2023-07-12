/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:02:00 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/12 16:27:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

RPN::RPN(std::string input){
	parse_input(input);
}
RPN::RPN(const RPN& new_object){*this = new_object;}
RPN::~RPN(){}

bool RPN::is_string_valid(const std::string& str){
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it) && *it != ' ' && *it != '*' && *it != '/' && *it != '+' && *it != '-') {
            return false;
        }
    }
    return true;
}

bool RPN::is_string_digit(const std::string& str){
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

int	RPN::parse_input(std::string input){
	if (input.empty())
		throw std::runtime_error("Error: empty input.");
	if (is_string_valid(input) == false)
		throw std::runtime_error("Error: invalid character.");
	std::stringstream 			ss(input);
	std::string 				token;
	std::string*				array = NULL;
	int							i = 0;

	while(std::getline(ss, token, ' ')){
		array[i] += token;
		i++;
	}
	if (i % 2 == 0)
		throw std::runtime_error("Error: wrong number of argument. The sum of digits and operand should always be odd");
	if (is_string_digit(array[0]) == false || is_string_digit(array[1]) == false)
		throw std::runtime_error("Error: values must be numbers between 0 and 9");

	std::istringstream value1(array[0]);
	int temp;
	value1 >> temp;
	if (temp < 1 || temp > 9)
		throw std::runtime_error("Error: values must be numbers between 0 and 9");
	_stack.push(temp);


	for(int j = 1; j < i; j++){
		int result = 0;
		std::istringstream value2(array[j]);
		value2 >> temp;
		if (temp < 1 || temp > 9)
			throw std::runtime_error("Error: values must be numbers between 0 and 9");
		if (array[j + 1] == "+")
			result = temp + _stack.top();
		else if (array[j + 1] == "-")
			result = temp - _stack.top();
		else if (array[j + 1] == "/")
			result = temp / _stack.top();
		else if (array[j + 1] == "*")
			result = temp * _stack.top();
		else
			throw std::runtime_error("Error: expected a operations token");
		_stack.pop();
		_stack.push(result);
		j += 2;		
	}
	std::cout << _stack.top() << std::endl;
	return (0);
}

RPN& RPN::operator=(const RPN& other){
	if(this != &other){
		this->_stack = other._stack;
	}
	return(*this);
}