/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:42:36 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/27 14:37:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void	Harl::_debug(void){
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
	<< std::endl;
}

void	Harl::_info(void){
	std::cout << 
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I would'nt be asking for more!"
	<< std::endl;
	
}

void	Harl::_warning(void){
	std::cout <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}
void	Harl::_error(void){
	std::cout <<
	"This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void	Harl::complain(std::string level){
	void		(Harl::*functions_array[4])(void) = {
	&Harl::_debug,
	&Harl::_info,
	&Harl::_warning,
	&Harl::_error};
	std::string	levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"};
	int			i = 0;
	
	while(i < 4){
		if(levels[i] == level){
			(this->*functions_array[i])();
			break ;
		}
		i++;
	}
}
