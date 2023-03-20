/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/19 18:37:29 by tbeaudoin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<string.h>
#include<iostream>

class Contact{
	
	public:
		Contact();
		~Contact();
	
		//GETTERS
		std::string	get_first_name() const;
		std::string	get_last_name()  const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_dark_secret() const;

		//SETTERS
		void	set_first_name(const std::string new_val);
		void	set_last_name(const std::string new_val);
		void	set_nickname(const std::string new_val);
		void	set_phone_number(const std::string new_val);
		void	set_dark_secret(const std::string new_val);

		
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _dark_secret;
		int			_index;
};

#endif