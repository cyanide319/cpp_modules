/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:06:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/17 14:44:55 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _swap_flag(0){};

PhoneBook::~PhoneBook(void) {};

int	PhoneBook::add_contact(){
	std::string	str;
	
	if (PhoneBook::_swap_flag == 1)
		PhoneBook::swap();
	
	std::cout << "Enter first name:";
	getline(std::cin, str);
	if (str.size() <= 0)
		return (-1);
	str = PhoneBook::format_str(str);
	contacts[PhoneBook::_index].set_first_name(str);

	std::cout << "Enter last name:";
	getline(std::cin, str);
	if (str.size() <= 0)
		return (-1);
	str = PhoneBook::format_str(str);
	contacts[PhoneBook::_index].set_last_name(str);
	
	std::cout << "Enter nickname:";
	getline(std::cin, str);
	if (str.size() <= 0)
		return (-1);
	str = PhoneBook::format_str(str);
	contacts[PhoneBook::_index].set_nickname(str);
	
	std::cout << "Enter phone number:";
	getline(std::cin, str);
	if (str.size() <= 0)
		return (-1);
	str = PhoneBook::format_str(str);
	contacts[PhoneBook::_index].set_phone_number(str);
	
	std::cout << "Enter dark secret:";
	getline(std::cin, str);
	if (str.size() <= 0)
		return (-1);
	str = PhoneBook::format_str(str);
	contacts[PhoneBook::_index].set_dark_secret(str);

	PhoneBook::_swap_flag = 0;
	if (PhoneBook::_index < 7)
		PhoneBook::_index++;
	else
	{
		PhoneBook::_index = 0;
		PhoneBook::_swap_flag = 1;
		
	}

	return (0);	
}

void	PhoneBook::swap(){
	contacts[7] = contacts[6];
	contacts[6] = contacts[5];
	contacts[5] = contacts[4];
	contacts[4] = contacts[3];
	contacts[3] = contacts[2];
	contacts[2] = contacts[1];
	contacts[1] = contacts[0];
}

int	PhoneBook::search_contact(){
	int			i = -1;
	std::string	input;

	while(++i < 8){
		std::cout << "|Index:" << std::setw(10) << i
		<< "|Frist name:" << std::setw(10) << contacts[i].get_first_name() 
		<< "|Last name:" << std::setw(10) << contacts[i].get_last_name() 
		<< "|Nickname:" << std::setw(10) << contacts[i].get_nickname() << "|"
		<< std::endl;
	}
	std::cout << "Enter index:";
	getline(std::cin, input);
	if(input == "0"){
		std::cout << "First name: " << contacts[0].get_first_name() << std::endl
		<< "Last name: " << contacts[0].get_last_name() << std::endl
		<< "Nickname: " << contacts[0].get_nickname() << std::endl
		<< "Phone number: " << contacts[0].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[0].get_dark_secret() << std::endl;
	}
	else if(input == "1"){
		std::cout << "First name: " << contacts[1].get_first_name() << std::endl
		<< "Last name: " << contacts[1].get_last_name() << std::endl
		<< "Nickname: " << contacts[1].get_nickname() << std::endl
		<< "Phone number: " << contacts[1].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[1].get_dark_secret() << std::endl;
	}
	else if(input == "2"){
		std::cout << "First name: " << contacts[2].get_first_name() << std::endl
		<< "Last name: " << contacts[2].get_last_name() << std::endl
		<< "Nickname: " << contacts[2].get_nickname() << std::endl
		<< "Phone number: " << contacts[2].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[2].get_dark_secret() << std::endl;
	}
	else if(input == "3"){
		std::cout << "First name: " << contacts[3].get_first_name() << std::endl
		<< "Last name: " << contacts[3].get_last_name() << std::endl
		<< "Nickname: " << contacts[3].get_nickname() << std::endl
		<< "Phone number: " << contacts[3].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[3].get_dark_secret() << std::endl;
	}
	else if(input == "4"){
		std::cout << "First name: " << contacts[4].get_first_name() << std::endl
		<< "Last name: " << contacts[4].get_last_name() << std::endl
		<< "Nickname: " << contacts[4].get_nickname() << std::endl
		<< "Phone number: " << contacts[4].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[4].get_dark_secret() << std::endl;
	}
	else if(input == "5"){
		std::cout << "First name: " << contacts[5].get_first_name() << std::endl
		<< "Last name: " << contacts[5].get_last_name() << std::endl
		<< "Nickname: " << contacts[5].get_nickname() << std::endl
		<< "Phone number: " << contacts[5].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[5].get_dark_secret() << std::endl;
	}
	else if(input == "6"){
		std::cout << "First name: " << contacts[6].get_first_name() << std::endl
		<< "Last name: " << contacts[6].get_last_name() << std::endl
		<< "Nickname: " << contacts[6].get_nickname() << std::endl
		<< "Phone number: " << contacts[6].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[6].get_dark_secret() << std::endl;
	}
	else if(input == "7"){
		std::cout << "First name: " << contacts[7].get_first_name() << std::endl
		<< "Last name: " << contacts[7].get_last_name() << std::endl
		<< "Nickname: " << contacts[7].get_nickname() << std::endl
		<< "Phone number: " << contacts[7].get_phone_number() << std::endl
		<< "Dark secret: " << contacts[7].get_dark_secret() << std::endl;
	}
	else
		std::cout << input << " is not a valid index." << std::endl;
	return (0);
}

std::string	PhoneBook::format_str(std::string str){
	if (str.size() > 9)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}
