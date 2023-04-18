/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:28:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/18 12:48:08 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Brain.hpp"

//DEFAULT CONSTRUCT
Brain::Brain(){}
//COPY CONSTRUCT
Brain::Brain(const Brain& new_object){}
//DEFAULT DESTROY
Brain::~Brain(){}


std::string	Brain::get_ideas(int i) const {if (i >= 0 && 1 <= 99) return (ideas[i]);}

void	Brain::set_ideas(int i, std::string new_val){if (i >= 0 && 1 <= 99) ideas[i] = new_val;}

Brain& Brain::operator=(const Brain& other){
	if (this != &other){
		*this->ideas = *other.ideas;
	}
    return (*this);
}