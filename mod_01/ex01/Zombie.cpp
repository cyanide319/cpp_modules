/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:02:45 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:46 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	std::cout << "A wild fucking horde appear" << std::endl;
}

Zombie::Zombie(std::string _name){
	Zombie::set_name(_name);
	std::cout << Zombie::get_name() << " has risen!" << std::endl;
}

Zombie::~Zombie(){
	std::cout << Zombie::get_name() << " has died! Again!" << std::endl;
}

std::string Zombie::get_name() const{
	return (_name);
}

void	Zombie::set_name(const std::string new_val){
		Zombie::_name = new_val;
}

void Zombie::announce( void ){
	std::cout << Zombie::get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}