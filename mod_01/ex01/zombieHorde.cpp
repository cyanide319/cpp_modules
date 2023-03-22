/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:35:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/21 17:23:57 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *newHorde = new Zombie[N];
	int	i = 0;

	while(i < N){
		newHorde[i].set_name(name);
		i++;
	}
	return (newHorde);
}
