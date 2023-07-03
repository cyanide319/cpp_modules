/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:57:19 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/03 13:24:17 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>

class Span{
	public:
		Span(unsigned int range);
		~Span();

		void			addNumber(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

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