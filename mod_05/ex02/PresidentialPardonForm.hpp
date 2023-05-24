/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:53 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/24 17:45:59 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#pragma once

#include"Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form{
	public:
		PresidentialPardonForm();	
		PresidentialPardonForm(std::string name);	
		PresidentialPardonForm(const PresidentialPardonForm& new_object);	
		~PresidentialPardonForm();
		
		int	execute(const Bureaucrat& bureaucrat) const;

		PresidentialPardonForm& 		operator=(const PresidentialPardonForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif