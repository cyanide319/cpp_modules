/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:53:02 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/01 17:15:35 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#pragma once


#include<iostream>
#include<cstdlib>
#include<ctime>
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

class Base{
	virtual~Base();

	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif