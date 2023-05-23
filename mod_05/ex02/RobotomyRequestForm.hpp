/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 18:52:57 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include <cstdlib>
#include <ctime>
#include"Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form{
	public:
		RobotomyRequestForm();	
		RobotomyRequestForm(std::string target);	
		RobotomyRequestForm(const RobotomyRequestForm& new_object);	
		~RobotomyRequestForm();

		void	execute();

		RobotomyRequestForm& 		operator=(const RobotomyRequestForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif