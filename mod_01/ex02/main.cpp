/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:13:58 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/23 14:16:23 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string& strREF = str;
	std::string* strPTR = &str;

	std::cout << std::endl << "Address of str: " << &str << std::endl;
	std::cout << "Address of strREF: " << &strREF << std::endl;
	std::cout << "Address of strPTR: " << strPTR << std::endl << std::endl;
	
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of strREF: " << strREF << std::endl;
	std::cout << "Value of strPTR: " << *strPTR << std::endl << std::endl;
}
