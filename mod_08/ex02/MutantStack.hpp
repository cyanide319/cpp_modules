/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:47:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/06 11:04:46 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<stack>
#include<deque>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		~MutantStack();

		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
    	typedef typename container_type::const_iterator const_iterator;

	
		void									push(T val);
		void									pop();
		T										top();
		bool									empty();
		size_t									size();
		typename MutantStack<T>::iterator 		begin();
		typename MutantStack<T>::iterator		end();
		typename MutantStack<T>::const_iterator	begin() const;
		typename MutantStack<T>::const_iterator	end() const;
	

		MutantStack<T>							operator++(int);
		MutantStack<T>&							operator++(void);
		MutantStack<T>							operator--(int);
		MutantStack<T>&							operator--(void);
	private:
		std::stack<T>							_mutant_stack;
		std::deque<T>							_stack_copy;
		typename std::deque<T>::const_iterator	_iter;
};

#include "MutantStack.tpp"

#endif