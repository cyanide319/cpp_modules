/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:34 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/07 10:37:59 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once

#include<iostream>

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& new_object);
        ~ClapTrap();

        void        set_name(std::string new_val);
        void        set_hit_point(int new_val);
        void        set_energy_point(int new_val);
        void        set_attack_damage(int new_val);

        std::string get_name(void) const;
        int         get_hit_point(void) const;
        int         get_energy_point(void) const;
        int         get_attack_damage(void) const;
		
        void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

		ClapTrap& 	operator=(const ClapTrap& other);

    private:
        std::string	_name;
		int			_hit_point;
		int			_energy_point;
		int			_attack_damage;
};

#endif