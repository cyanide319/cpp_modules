/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:45:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/18 13:24:41 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include<iostream>

class Form{
	public:
		Form(std::string name, int to_sign, int to_exec);	
		Form(const Form& new_object);	
		~Form();

		std::string get_name(void) const;
		int			get_to_sign(void) const;
		int			get_to_exec(void) const;
		bool		get_signed(void) const;

		void		set_signed(bool new_val);

		Form& Form::operator=(const Form& other);
	private:
		const	std::string	_name;
		const	int			_to_sign;
		const	int			_to_exec;
		bool				_signed;
};

#endif