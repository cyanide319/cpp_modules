/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:35:45 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:05:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
	Weapon::setType(type);
}

Weapon::~Weapon() {}

void Weapon::setType(const std::string new_val){
	type = new_val;
}

std::string	Weapon::getType() const{
	return (type);
}