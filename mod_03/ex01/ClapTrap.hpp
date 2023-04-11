/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:34 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 15:54:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once

#include<iostream>

#define BLUE_CL "\033[1;36m"
#define WHITE_CL "\033[0;37m"
#define RED_CL "\033[0;31m"
#define YELLOW_CL "\033[0;33m"
#define PINK_CL "\033[38;2;255;192;203m"

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& new_object);
    	virtual ~ClapTrap();

        void        	set_name(std::string new_val);
        void        	set_type(std::string new_val);
        void        	set_hit_point(int new_val);
        void        	set_max_hit_point(int new_val);
        void        	set_energy_point(int new_val);
        void        	set_attack_damage(int new_val);

        std::string 	get_name(void) const;
        std::string 	get_type(void) const;
        int         	get_hit_point(void) const;
        int         	get_max_hit_point(void) const;
        int         	get_energy_point(void) const;
        int         	get_attack_damage(void) const;
		
        void			attack(const std::string& target);
		virtual void 	takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

		ClapTrap& 	operator=(const ClapTrap& other);

    protected:
        std::string	_name;
		std::string	_type;
		int			_hit_point;
		int			_energy_point;
		int			_attack_damage;
		int			_max_hit_point;
};

#endif