/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:29:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/23 17:05:25 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include<iostream>
#include<string>
#include<fstream>

class File{
	public:
		File(const std::string& infile, std::string& s1, std::string& s2);
		~File();

		std::string	get_s1() const;
		std::string	get_s2() const;
		std::string	get_infile() const;
		std::string	get_outfile() const;

		void		set_s1(const std::string& new_val);
		void		set_s2(const std::string& new_val);
		void		set_infile(const std::string& new_val);
		void		set_outfile(const std::string& new_val);

	private:
		std::string	_s1;
		std::string	_s2;
		std::string	_infile;
		std::string	_outfile;
};


#endif