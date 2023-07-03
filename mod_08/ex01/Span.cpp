/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:57:16 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/03 14:15:59 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

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

struct EqualToValue {
    int value;
    EqualToValue(int val) : value(val) {}
    bool operator()(int element) const {
        return element == value;
    }
};

unsigned int	Span::shortestSpan(){
	if (_index <= 1)
		throw NoSpan();
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	if (min == _vector.end())
		throw NoSpan();

	std::vector<int>::iterator second_low = min + 1;
	std::vector<int>::iterator iter;

	for (unsigned int i = 0; i < _index; i++){
		iter = std::find_if(_vector.begin(), _vector.end(),  EqualToValue(*second_low));
		if (iter == _vector.end())
			second_low++;
		else
			break ;
	}

	if (iter == _vector.end())
		throw NoSpan();
	// std::ptrdiff_t ret = iter - min;
	else
		return (static_cast<unsigned int>(std::distance(min, iter)));
}

unsigned int	Span::longestSpan(){
	if (_index <= 1)
		throw NoSpan();
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	if (min == _vector.end())
		throw NoSpan();
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	if (max == _vector.end())
		throw NoSpan();
	else
		return (static_cast<unsigned int>(std::distance(min, max)));
}