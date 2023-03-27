/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:25:11 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/27 12:43:26 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<fstream>

int	main(int argc, char **argv)
{
	if( argc == 4){
		std::string	line;
		std::string	infile = argv[1];
		std::string	s1 = argv[2];
		std::string	s2 = argv[3];
		std::string	outfile = "outfile.replace";
		size_t		pos;

		std::ifstream Infile(infile);
		std::ofstream Outfile(outfile);

		if (Infile.is_open()){
			// pos = line.find(s1);
			while(getline(Infile, line)){
				int	i = 0;
				while((pos = line.find(s1)) != -1){
					line.erase(pos, s1.size());
					line.insert(pos, s2);
				}
				Outfile << line << std::endl;
			}
			
			Infile.close();
			Outfile.close();
		}
		else
			std::cout << "Bad file" << std::endl;
	}
	else
		std::cout << "<infile name> <str 1> <str 2>" << std::endl;
	
}