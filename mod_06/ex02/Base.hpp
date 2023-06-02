/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:53:02 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/02 15:28:26 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#pragma once


#include<iostream>
#include<cstdlib>
#include<ctime>

class Base{
	public:
		virtual~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif