/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/19 18:39:52 by tbeaudoin        ###   ########.fr       */
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
		void	swap();

		std::string	format_str(std::string str);
		
		PhoneBook();
		~PhoneBook();
	
	private:
		Contact contacts[8];
		int		_index;
};

#endif