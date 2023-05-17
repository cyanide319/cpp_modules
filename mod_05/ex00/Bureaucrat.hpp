/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:12:24 by tristan           #+#    #+#             */
/*   Updated: 2023/05/17 14:51:38 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#define BLUE_CL "\033[1;36m"
#define WHITE_CL "\033[0;37m"
#define RED_CL "\033[0;31m"
#define YELLOW_CL "\033[0;33m"
#define PINK_CL "\033[38;2;255;192;203m"
#define GREEN_CL "\033[0;32m"

#include<iostream>
#include<string>
#include<exception>

class Bureaucrat{
    public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& new_object);
		~Bureaucrat();

		void		set_grade(int new_val);

		std::string	get_name(void) const;
		int			get_grade(void) const;

		void	grade_up();
		void	grade_down();

		class GradeTooHighException: public std::exception{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char * what() const throw();
		};

		Bureaucrat& operator=(const Bureaucrat& other);

    private:
        const std::string	_name;
        int					_grade;
};

#endif