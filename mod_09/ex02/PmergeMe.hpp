/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:19 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/13 15:17:24 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe{
	public:
		PmergeMe(std::string input);
		PmergeMe(const PmergeMe& new_object);
		~PmergeMe();


		bool						is_string_digit(const std::string& str);
		bool						is_string_int(const std::string& str);
		std::vector<std::string>	split_vectors(std::string str, char delimiter);
		int							parse_input(std::string input);
		template <typename T>
		int							sort_algo(T& input);
		// int							parse_deque(std::vector<std::string> input);

		PmergeMe& operator=(const PmergeMe& other);
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		int					_temp;
};


#endif