/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:17:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/08 12:41:07 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"
#include"color.h"
#include<ostream>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << PINK << x << std::endl; return; }

template< typename T >
void increment(int& val){val++;}

int main() {
  int tab[] = { 0, 1, 2, 3, 4};
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  std::cout << std::endl;
  iter( tab2, 5, print<Awesome> );
  std::cout << std::endl;
  iter( tab, 5, increment<int> );
  iter( tab, 5, print<int> );

  return 0;
}
