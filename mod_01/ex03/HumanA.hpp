/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:37:49 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/23 11:11:20 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack();

		std::string getName() const;
		Weapon		getWeapon() const;

		void 		setName(const std::string new_val);
		void		setWeapon(const Weapon& new_val);

	private:
		std::string	name;
		Weapon&		weapon;
};

#endif