/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:13:13 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/10 14:38:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(){
	try{
		BitcoinExchange test("./data.csv");
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	
}