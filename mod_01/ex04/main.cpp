/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:25:11 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/24 13:35:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include"File.hpp"

#include<iostream>
#include<string>
#include<fstream>

// File::File(const std::string& infile, std::string& s1, std::string& s2): _infile(infile), _s1(s1), _s2(s2), _outfile("outfile.replace"){}

// File::~File() {}

// std::string File::get_s1() const{
// 	return (_s1);
// }
// std::string File::get_s2() const{
// 	return (_s2);
// }
// std::string File::get_infile() const {
// 	return (_infile);
// }
// std::string File::get_outfile() const{
// 	return (_outfile);
// }

// void		File::set_s1(const std::string& new_val){
// 	_s1 = new_val;
// }
// void		File::set_s2(const std::string& new_val){
// 	_s2 = new_val;
// }
// void		File::set_infile(const std::string& new_val){
// 	_infile = new_val;
// }
// void		File::set_outfile(const std::string& new_val){
// 	_outfile = new_val;
// }

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