/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:35:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:05:26 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include<iostream>

class Weapon{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string getType() const;
		
		void		setType(const std::string new_val);

	
	private:
		std::string type;
};

#endif