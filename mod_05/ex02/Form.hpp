/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:45:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 16:22:06 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include<iostream>
#include<exception>
#include"Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
		Form();	
		Form(std::string name, int to_sign, int to_exec);	
		Form(const Form& new_object);	
		~Form();

		std::string 	get_name(void) const;
		std::string 	get_target(void) const;
		int				get_to_sign(void) const;
		int				get_to_exec(void) const;
		bool			get_signed(void) const;

		void			set_signed(bool new_val);
		void			set_target(std::string new_val);

		int				beSigned(const Bureaucrat& bureaucrat);
		int				beExecuted(const Bureaucrat& bureaucrat);
		virtual	void	execute() = 0;

		class GradeTooHighException: public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char * what() const throw();
		};

		Form& 			operator=(const Form& other);
	private:
		const	std::string	_name;
		std::string			_target;
		const	int			_to_sign;
		const	int			_to_exec;
		bool				_signed;
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif