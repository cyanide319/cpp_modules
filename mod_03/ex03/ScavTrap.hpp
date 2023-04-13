/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:26:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/13 11:33:23 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include"ClapTrap.hpp"
#include<iostream>

class ScavTrap: virtual public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& new_object);
        virtual ~ScavTrap();

		void			set_guard_mode(bool new_val);

		bool			get_guard_mode(void) const;
		
		virtual void 	takeDamage(unsigned int amount);
		void			guardGate(void);

		ScavTrap& 	operator=(const ScavTrap& other);
	protected:
		static const int	_scav_hit_point = 100;
		static const int	_scav_energy_point = 50;
		static const int	_scav_attack_damage = 20;
	private:
		bool						_guard_mode;
		static const int			_guard_dr = 5;
};

#endif