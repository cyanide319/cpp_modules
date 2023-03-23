/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:56:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/23 14:14:50 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL){
	HumanB::setName(name);
}

HumanB::~HumanB() {}

std::string	HumanB::getName() const{
	return (name);
}

Weapon* HumanB::getWeapon() const{
	return (weapon);
}

void HumanB::setName(const std::string new_val){
	name = new_val;
}

void	HumanB::setWeapon(Weapon& new_val){
	weapon = &new_val;
}

void	HumanB::attack(){
	if (weapon == NULL)
	{
		std::cout << HumanB::getName() << " don't have any weapon" << std::endl;
		return ;
	}
	std::cout << HumanB::getName()  << " attack with their " << weapon->getType() << std::endl;
}
