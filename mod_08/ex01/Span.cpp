/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:57:16 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/04 14:15:57 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"
#include <iostream>

Span::Span(unsigned int range): _index(0), N(range){}

Span::~Span(){}

const char* Span::LimitReached::what() const throw() {return ("The array is full");}
const char* Span::NoSpan::what() const throw() {return ("No span can be found");}

void	Span::addNumber(int nb){
	if (_index < N)
		_vector.push_back(nb);
	else
		throw LimitReached();
	_index++;
}

void Span::addRange(std::vector<int> range){
	if (_index + range.size() > N)
		throw LimitReached();
	else
		_vector.insert(_vector.end(), range.begin(), range.end());
	_index += range.size();
}

int	Span::shortestSpan(){
	if (_index <= 1)
		throw NoSpan();
	std::vector<int>::iterator iter;
	std::vector<int>::iterator iter2;
	std::vector<int> temp(_vector.begin(), _vector.end());
	int span = std::numeric_limits<int>::max();
	for (iter = temp.begin(); iter != temp.end(); ++iter){
		for (iter2 = iter + 1; iter2 != temp.end(); ++iter2){
			int dif = std::abs(*iter2 - *iter);
			if (dif < span)
				span = dif;
		}
	}
	return (span);
}

int	Span::longestSpan(){
	if (_index <= 1)
		throw NoSpan();
	std::vector<int> temp(_vector.begin(), _vector.end());
	std::vector<int>::iterator min = std::min_element(temp.begin(), temp.end());
	if (min == _vector.end())
		throw NoSpan();
	std::vector<int>::iterator max = std::max_element(temp.begin(), temp.end());
	if (max == _vector.end())
		throw NoSpan();
	else
		return (*max - *min);
}