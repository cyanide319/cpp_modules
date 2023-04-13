/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:29 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/13 11:43:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#pragma once

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"
#include<iostream>

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& new_object);
        virtual ~DiamondTrap();

		virtual void   	set_name(std::string new_val);

        virtual std::string	get_name(void) const;

		using			ScavTrap::attack;
		void 			whoAmI();

		DiamondTrap&	operator=(const DiamondTrap& other);
	private:
		std::string	_name;
};

#endif