/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/14 17:34:23 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include"PhoneBook.hpp"

class Contact{
	public:
		Contact();
		~Contact();
	
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _ph_number;
		std::string _dark_secret;
	
};

#endif