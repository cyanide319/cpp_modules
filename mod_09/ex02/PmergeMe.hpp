/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:19 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/18 15:29:08 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <sys/time.h>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(std::string input);
		PmergeMe(const PmergeMe& new_object);
		~PmergeMe();


		bool						is_string_digit(const std::string& str);
		bool						is_string_int(const std::string& str);
		std::vector<std::string>	split_vectors(std::string str, char delimiter);
		int							parse_input(std::string input);
		void						print_vector();
		void						print_list();
		void						sort_vector(int start, int end);
		void						sort_list(int start, int end);
		void						is_sorted();
	
		template <typename Container>
		void 						merge_container(Container& container, int start, int middle, int end);
		

		PmergeMe& operator=(const PmergeMe& other);
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		int					_temp;
		int					_size;
};


#endif