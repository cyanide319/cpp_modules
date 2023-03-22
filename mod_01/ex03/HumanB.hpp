/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:37:10 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:05:05 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name, Weapon weapon);
		HumanB(std::string name);
		~HumanB();

		void	attack();

		std::string getName() const;
		Weapon		getWeapon() const;

		void		setName(const std::string new_val);
		void		setWeapon(const Weapon new_val);

	private:
		std::string	name;
		Weapon		weapon;
};

#endif