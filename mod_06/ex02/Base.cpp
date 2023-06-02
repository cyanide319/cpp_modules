/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:08:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/01 17:20:10 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"

Base* Base::generate(void){
	std::srand(std::time(NULL));

	int randomNumber;
	randomNumber = std::rand() % 3 + 1;
	if (randomNumber == 1){
		Base ret;
		static_cast<A>(ret);
	}
	if (randomNumber == 2)
		Base ret = new B;
	if (randomNumber == 3)
		Base ret = new C;
	return (ret);
}
void Base::identify(Base* p){
	
}
void Base::identify(Base& p){
	
}