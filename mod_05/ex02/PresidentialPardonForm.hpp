/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:53 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/19 13:33:44 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#pragma once

#include"Form.hpp"

class Bureaucrat;

class PresidentialPardonForm{
	public:
		PresidentialPardonForm(std::string name, int to_sign, int to_exec);	
		PresidentialPardonForm(const PresidentialPardonForm& new_object);	
		~PresidentialPardonForm();

		std::string get_name(void) const;
		int			get_to_sign(void) const;
		int			get_to_exec(void) const;
		bool		get_signed(void) const;

		void	set_signed(bool new_val);

		virtual int		beSigned(Bureaucrat& bureaucrat) = 0;

		PresidentialPardonForm& 		operator=(const PresidentialPardonForm& other);
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif