/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:30:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/19 14:11:44 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include"Form.hpp"

class Bureaucrat;

class RobotomyRequestForm{
	public:
		RobotomyRequestForm(std::string target);	
		RobotomyRequestForm(const RobotomyRequestForm& new_object);	
		~RobotomyRequestForm();

		std::string get_name(void) const;
		int			get_to_sign(void) const;
		int			get_to_exec(void) const;
		bool		get_signed(void) const;

		void	set_signed(bool new_val);

		virtual int		beSigned(Bureaucrat& bureaucrat) = 0;

		RobotomyRequestForm& 		operator=(const RobotomyRequestForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif