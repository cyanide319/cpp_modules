/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:59:36 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/24 17:58:02 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& new_object);
		~Intern();

		Form*	makeForm(std::string name, std::string target);
		Intern& operator=(const Intern& other);
	private:
		std::string _forms_name[3];
};

#endif