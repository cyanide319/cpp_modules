/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:45:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/18 12:59:02 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

class Form{
	public:
		Form(std::string name, int to_sign, int to_exec);	
		Form(const Form& new_object);	
		~Form();

	private:
		const	std::string	_name;
		const	int			_to_sign;
		const	int			_to_exec;
		bool				_signed:
};

#endif