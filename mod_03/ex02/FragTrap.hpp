/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:54:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 18:57:25 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include"ClapTrap.hpp"
#include<iostream>

class FragTrap: public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& new_object);
        virtual ~FragTrap();

		void		highFivesGuys(void);

		FragTrap& 	operator=(const FragTrap& other);
};

#endif