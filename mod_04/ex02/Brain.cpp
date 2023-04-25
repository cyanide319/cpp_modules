/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:28:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/25 13:20:48 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Brain.hpp"

//DEFAULT CONSTRUCT
Brain::Brain(){ std::cout << "Brain default construct" << std::endl;}

Brain::Brain(std::string new_ideas[100]){
	int	i = 0;
		while (i < 100){
			this->ideas[i] = new_ideas[i];
			i++;
		}
		std::cout << "Brain idea construct" << std::endl;
	}

//COPY CONSTRUCT
Brain::Brain(const Brain& new_object){
	int i = 0;
	while (i < 100){
		this->ideas[i] = new_object.get_ideas(i);
		i++;
	}
	std::cout << "Brain copy construct" << std::endl;}

//DEFAULT DESTROY
Brain::~Brain(){ std::cout << "Brain destructor" << std::endl;}

//GETTER
std::string	Brain::get_ideas(int i) const {
	if (i >= 0 && 1 <= 99)
		return (ideas[i]);
	return (ideas[0]);}

//SETTER
void	Brain::set_ideas(int i, std::string new_val){if (i >= 0 && 1 <= 99) ideas[i] = new_val;}


//OVERLOAD
Brain& Brain::operator=(const Brain& other){
	if (this != &other){
		int	i = 0;
		while (i < 100){
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
    return (*this);
}