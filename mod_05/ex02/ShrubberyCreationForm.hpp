/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:26:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/19 16:19:39 by tbeaudoi         ###   ########.fr       */
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
		ShrubberyCreationForm(std::string target);	
		ShrubberyCreationForm(const ShrubberyCreationForm& new_object);	
		~ShrubberyCreationForm();

		// std::string get_name(void) const;
		// int			get_to_sign(void) const;
		// int			get_to_exec(void) const;
		// bool		get_signed(void) const;

		// void		set_signed(bool new_val);

		void	execute(const Bureaucrat& bureaucrat);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif