/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:19:00 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/06 10:54:01 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}
template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
void	MutantStack<T>::push(T val){
	_mutant_stack.push(val);
	_stack_copy.push_back(_mutant_stack.top());
}

template <typename T>
void	MutantStack<T>::pop(){
	_stack_copy.pop_back();
	_mutant_stack.pop();
}

template <typename T>
T	MutantStack<T>::top(){
	return (_mutant_stack.top());
}

template <typename T>
bool	MutantStack<T>::empty(){
	return (_mutant_stack.empty());
}

template <typename T>
size_t	MutantStack<T>::size(){
	return (_mutant_stack.size());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(){
	return (_stack_copy.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){
	return (_stack_copy.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
	return (_stack_copy.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
	return (_stack_copy.end());
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator--(void){
	_iter++;
    return (*this);
}

template <typename T>
MutantStack<T>	MutantStack<T>::operator--(int){
    MutantStack<T> temp = _iter->_stack_copy;
	_iter--;
    return (temp);
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator++(void){
	_iter++;
    return (*this);
}

template <typename T>
MutantStack<T>	MutantStack<T>::operator++(int){
    MutantStack<T> temp = _iter->_stack_copy;
	_iter++;
    return (temp);
}
