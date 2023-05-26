/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:47:16 by tristan           #+#    #+#             */
/*   Updated: 2023/05/25 16:50:24 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

int main(int argc, char **argv){
	if (argc < 2 || argc > 2){
		std::cout << "Need to pass a char, an int, a float or a double as an argument." << std::endl;
		return (1);
	}
	std::string	base = argv[1];
	Converter convert(base);
	convert.convert();
	std::cout << convert;
}
