/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 14:05:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include<thread>
#include<chrono>
#include<random>
#include"Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form{
	public:
		RobotomyRequestForm(std::string target);	
		RobotomyRequestForm(const RobotomyRequestForm& new_object);	
		~RobotomyRequestForm();

		void	execute();

		RobotomyRequestForm& 		operator=(const RobotomyRequestForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif