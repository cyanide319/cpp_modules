/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:47:16 by tristan           #+#    #+#             */
/*   Updated: 2023/05/31 12:17:16 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

int main(int argc, char **argv){
	if (argc < 2 || argc > 2){
		std::cout << "Need to pass a char, an int, a float or a double as an argument." << std::endl;
		return (1);
	}
	try{
		std::string	base = argv[1];
		Converter convert(base);
		try{
			std::cout << convert;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
			return (1);
		}
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		return (1);
	}
}
