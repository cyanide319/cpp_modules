/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:57:19 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/06 12:02:22 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iterator>

class Span{
	public:
		Span(unsigned int range);
		~Span();

		void	addNumber(int nb);
		void	addRange(std::vector<int> range);
		int		shortestSpan();
		int		longestSpan();

		class LimitReached: public std::exception{
			public:
				const char* what() const throw();
		};
		class NoSpan: public std::exception{
			public:
				const char* what() const throw();
		};

	private:
		unsigned int		_index;
		unsigned int		N;
		std::vector<int>	_vector;
};

#endif