/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:02:00 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/22 15:53:23 by tbeaudoi         ###   ########.fr       */
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

int RPN::string_to_digit(std::string to_convert){
	std::istringstream value(to_convert);
	int temp;
	value >> temp;
	if (temp < 0 || temp > 9){
		throw std::runtime_error("Error: values must be numbers between 0 and 9");
	}
	return (temp);
}

void RPN::parse_input(std::string input){
	if (input.empty())
		throw std::runtime_error("Error: empty input.");
	if (is_string_valid(input) == false)
		throw std::runtime_error("Error: invalid character.");
	std::stringstream 			ss(input);
	std::string 				token;
	int							temp1;
	int							temp2;
	int							result;
	

	while(std::getline(ss, token, ' ')){
		temp1 = 0;
		temp2 = 0;
		result = 0;
		if (is_string_digit(token) == true){
			_stack.push(string_to_digit(token));
		}

		else if (token == "+" || token == "-" || token == "*" || token == "/" ){
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Should have at least two digits in the stack.");
			temp1 = _stack.top();
			_stack.pop();
			temp2 = _stack.top();
			_stack.pop();
			if (token == "+")
				result = temp2 + temp1;
			else if (token == "-")
				result = temp2 - temp1;
			else if (token == "/")
				result = temp2 / temp1;
			else if (token == "*")
				result = temp2 * temp1;
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error: Something wrong with the input.");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Needed more operations.");
	std::cout << _stack.top() << std::endl;
}

RPN& RPN::operator=(const RPN& other){
	if(this != &other){
		this->_stack = other._stack;
	}
	return(*this);
}