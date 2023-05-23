/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:26:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:55 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#pragma once

#include"Form.hpp"
#include<fstream>

class Bureaucrat;

class ShrubberyCreationForm: public Form{
	public:
		ShrubberyCreationForm();	
		ShrubberyCreationForm(std::string target);	
		ShrubberyCreationForm(const ShrubberyCreationForm& new_object);	
		~ShrubberyCreationForm();

		void	execute();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif