/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:26:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 15:52:50 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include"ClapTrap.hpp"
#include<iostream>

class ScavTrap: public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& new_object);
        virtual ~ScavTrap();

		void			set_guard_mode(bool new_val);

		bool			get_guard_mode(void) const;
		
        // virtual void 	attack(const std::string& target);
		virtual void 	takeDamage(unsigned int amount);
		void			guardGate(void);

		ScavTrap& 	operator=(const ScavTrap& other);
	private:
		bool						_guard_mode;
		static const int			_guard_dr = 5;
};

#endif