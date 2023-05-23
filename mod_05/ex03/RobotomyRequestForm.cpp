/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 16:34:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

//DEFAULT CONSTRUCT
RobotomyRequestForm::RobotomyRequestForm():
Form("Robotomy Request", 72, 45){set_target("default");}

//NAMED CONSTRUCT
RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form("Robotomy Request", 72, 45){set_target(target);}

//COPY CONSTRUCT
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& new_object):
Form(new_object.get_name(), 72, 45){
	*this = new_object;
}

//DEFAULT DESTRUCT
RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::execute(){
	std::cout << "*Ominous drilling noises*" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "*More ominous drilling noises*" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "*Some ominous drilling noises later*" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 100);
	int randomNumber = distribution(generator);
	if (randomNumber > 50)
		std::cout << "The procedure is a success! The vict...Uh...The target: "
			<< get_target() <<" as been robotomized!" << std::endl;
	else
		std::cout << "Something totally out of our control failed. "
			"This is not covered by your insurance and you will be charged for the cleaning. "
			"Thank you, and have a good day." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}