/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:02:58 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/22 15:52:31 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <stdexcept>
#include <sstream>

class RPN {
	public:
		RPN(std::string input);
		RPN(const RPN& new_object);
		~RPN();

		void		parse_input(std::string input);
		int		string_to_digit(std::string to_convert);
		bool	is_string_valid(const std::string& str);
		bool	is_string_digit(const std::string& str);

		RPN& operator=(const RPN& other);
	private:
		std::stack<int> _stack;
};

#endif