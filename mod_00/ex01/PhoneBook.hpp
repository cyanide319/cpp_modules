/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/21 12:54:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include<iostream>
#include<iomanip>
#include<string>
#include"Contact.hpp"

class PhoneBook{
	public:
		int		add_contact();
		int		search_contact();

		std::string	format_str(std::string str);
		
		PhoneBook();
		~PhoneBook();
	
	private:
		Contact contacts[8];
		int		_index;
};

#endif