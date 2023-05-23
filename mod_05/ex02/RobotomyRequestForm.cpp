/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 18:52:39 by tristan          ###   ########.fr       */
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
	std::cout << "*More ominous drilling noises*" << std::endl;
	std::cout << "*Some ominous drilling noises later*" << std::endl;

    std::srand(std::time(nullptr));

	int randomNumber;
    for (int i = 0; i < 5; ++i) {
        randomNumber = std::rand() % 10 + 1;
    }
	if (randomNumber > 50)
		std::cout << "The procedure is a success! The vict...Uh...The target: "
			<< get_target() <<" as been robotomized!" << std::endl;
	else
		std::cout << "Something totally out of our control failed. "
			"This is not covered by your insurance and you will be charged for the cleaning. "
			"Thank you, and have a good day." << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}