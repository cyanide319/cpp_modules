/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:58:57 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:04:33 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class Zombie{
	
	public:
		Zombie(void);
		Zombie(std::string _name);
		~Zombie();

	void	announce(void);
	
	//GETTERS
	std::string get_name() const;

	//SETTERS
	void	set_name(const std::string new_val);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
Zombie*	newZombie(std::string name);

#endif