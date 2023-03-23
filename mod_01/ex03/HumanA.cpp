/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:42:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/23 11:31:13 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon) {
	HumanA::setName(name);
}

HumanA::~HumanA() {}

std::string	HumanA::getName() const{
	return (name);
}

Weapon HumanA::getWeapon() const{
	return (weapon);
}

void HumanA::setName(const std::string new_val){
	name = new_val;
}

void	HumanA::setWeapon(const Weapon& new_val){
	weapon = new_val;
}

void	HumanA::attack(){
	std::cout << HumanA::getName()  << " attack with their " << weapon.getType() << std::endl;
}
