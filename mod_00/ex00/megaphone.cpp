/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:21:49 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/14 14:23:09 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv){
	std::string str;
	int	i = 0;
	int	j = 1;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (j < argc){
		str = argv[j];
		i = 0;
		while (str[i]){
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i++;
			}
		std::cout << str;
		if (argv + 1)
			std::cout << " ";
		j++;
	}
	std::cout << std::endl;
	return (0);
}
