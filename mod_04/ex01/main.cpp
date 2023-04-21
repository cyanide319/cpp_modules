/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:09:16 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/21 13:15:49 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"

int main()
{
	std::string	strdog[100] = {"barnak", "fucking", "fuck", "dla", "marde", ""};
	std::string	strcat[100] = {"barmeow", "fuckingmeow", "fuckmeow", "dlameow", "meowrde", ""};
	const Animal* jo = new Dog(strdog);
	const Animal* io = new Cat();


	io->get_brain().set_ideas(0, "whatever");
	io->get_brain().set_ideas(1, "whatever1");
	io->get_brain().set_ideas(2, "whatever2");
	io->get_brain().set_ideas(3, "whatever3");
	io->get_brain().set_ideas(4, "whatever4");
	
	for (int i2 = 0; i2 < 6; i2++){
		std::cout << io->get_brain().get_ideas(i2) << std::endl;
		std::cout << RED_CL << jo->get_brain().get_ideas(i2) << std::endl << WHITE_CL;
	}
	
	delete jo;
	delete io;

	std::cout << std::endl<< "------------------------" << std::endl;
	//////////////////////////////////////////

	const Animal* whatever[10];
	int i = 0;

	while (i < 10){
		if (i < 5)
			whatever[i] = new Dog(strdog);
		else
			whatever[i] = new Cat(strcat);
		i++;	
	}
	std::cout << std::endl<< "------------------------" << std::endl;
	
	for (int j = 0; j < 5; j++)	std::cout << PINK_CL << whatever[0]->get_brain().get_ideas(j) << std::endl << WHITE_CL;
	for (int j = 0; j < 5; j++)	std::cout << YELLOW_CL << whatever[5]->get_brain().get_ideas(j) << std::endl << WHITE_CL;

	std::cout << std::endl<< "------------------------" << std::endl;
	const Cat* bob = new Cat(*((Cat *)whatever[6]));
	std::cout << std::endl<< "------------------------" << std::endl;
	
	i = 0;
	while (i < 10){
		delete whatever[i++];
	}
	
	std::cout << std::endl<< "------------------------" << std::endl;
	
	for (int j = 0; j < 5; j++)	std::cout << PINK_CL << bob->get_brain().get_ideas(j) << std::endl << WHITE_CL;
	for (int j = 0; j < 100; j++)bob->get_brain().set_ideas(j, strdog[j]);
	for (int j = 0; j < 5; j++)	std::cout << YELLOW_CL << bob->get_brain().get_ideas(j) << std::endl << WHITE_CL;
	
	delete bob;

	return 0;
}