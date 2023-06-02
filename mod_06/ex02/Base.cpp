/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:08:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/02 15:31:28 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

Base::~Base(){}

Base* generate(void){
	std::srand(std::time(NULL));

	int randomNumber;
	randomNumber = std::rand() % 3 + 1;
	if (randomNumber == 1){
		std::cout << "Type A generate" << std::endl;
		return (new A());
	}
	else if (randomNumber == 2){
		std::cout << "Type B generate" << std::endl;
		return (new B());
	}
	else{
		std::cout << "Type C generate" << std::endl;
		return (new C());
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "Type of pointer is: A" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "Type of pointer is: B" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "Type of pointer is: C" << std::endl;
}

void identify(Base& p){
	try{
		A& ref = dynamic_cast<A&>(p);
		(void)ref;
		std::cout << "Type of reference is: A" << std::endl;
	}
	catch(const std::exception& e){
	}
	try{
		B& ref = dynamic_cast<B&>(p);
		(void)ref;
		std::cout << "Type of reference is: B" << std::endl;
	}
	catch(const std::exception& e){
	}
	try{
		C& ref = dynamic_cast<C&>(p);
		(void)ref;
		std::cout << "Type of reference is: C" << std::endl;
	}
	catch(const std::exception& e){

	}
}
