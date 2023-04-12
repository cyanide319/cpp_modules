/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:54:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/12 19:08:22 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include"ClapTrap.hpp"
#include<iostream>

class FragTrap: virtual public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& new_object);
        virtual ~FragTrap();

		void		highFivesGuys(void);

		FragTrap& 	operator=(const FragTrap& other);
	protected:
		static const int	_frag_hit_point = 100;
		static const int	_frag_energy_point = 100;
		static const int	_frag_attack_damage = 30;
		static const int	_max_hit_point = _frag_hit_point;
};

#endif