/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:22 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/23 12:00:58 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_size(0){}

PmergeMe::PmergeMe(std::string input):_size(0){
	_vector.clear();
	_list.clear();
	parse_input(input);
	
	struct timeval start, end;
	long seconds, microseconds;

	std::cout << "Before :";
	print_vector();
	std::cout << std::endl;
	gettimeofday(&start, NULL);
	sort_vector(0, (_vector.size() - 1));
	gettimeofday(&end, NULL);
	std::cout << "After :";
	print_vector();
	std::cout << std::endl;
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double vector_time = (seconds * 1000) + (microseconds / 1000.0);
    std::cout << "Time elapsed for std::vector : " << vector_time << " milliseconds" << std::endl;
	std::cout << std::endl;
	
	gettimeofday(&start, NULL);
	sort_list(0, (_list.size() - 1));
	gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double list_time = (seconds * 1000) + (microseconds / 1000.0);
    std::cout << "Time elapsed for std::list : " << list_time << " milliseconds" << std::endl;
	std::cout << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe& new_object):_size(0){*this = new_object;}

PmergeMe::~PmergeMe(){}

void	PmergeMe::is_sorted(){

	for(size_t i = -1; i < _vector.size(); ++i){
		if (_vector[i] > _vector[i + 1]){
			std::cout << _vector[i] << " " << _vector[i + 1] << std::endl;
			std::cout << "Vector is not sorted" << std::endl;
			return ;
		}
	}
	std::cout << "Vector is sorted " << std::endl;

	std::list<int>::iterator it;
	for(it = _list.begin(); it != _list.end(); ++it){
		if (*it > *it + 1){
			std::cout << "List is not sorted" << std::endl;
			return ; 
		}
	}
	std::cout << "List is sorted" << std::endl;
}





template <typename Container>
void PmergeMe::merge_container(Container& container, int start, int middle, int end){
	Container temp;

	int left_index = start;
	int right_index = (middle + 1);
		
	typename Container::iterator left_iter = container.begin();
	std::advance(left_iter, start);
	typename Container::iterator right_iter = container.begin();
	std::advance(right_iter, (middle + 1));
	
	while (left_index <= middle && right_index <= end){
		if (*left_iter <= *right_iter){
			temp.push_back(*left_iter);
			left_iter++;
			left_index++;
		}
		else{
			temp.push_back(*right_iter);
			right_iter++;
			right_index++;
		}
	}

	while (left_index <= middle){
		temp.push_back(*left_iter);
		left_iter++;
		left_index++;
	}
	while (right_index <= end){
		temp.push_back(*right_iter);
		right_iter++;
		right_index++;
	}

	typename Container::iterator temp_iter = temp.begin();
	typename Container::iterator _iter = container.begin();
	std::advance(_iter, start);

	while(start <= end){
		*_iter = *temp_iter;
		temp_iter++;
		_iter++;
		++start;
	}
}





//VECTOR SORT

void PmergeMe::sort_vector(int start, int end){
	if ((end - start) > 5){
		int middle = ((start + end) / 2);
		
		sort_vector(start, middle);
		sort_vector((middle + 1), end);
		
		merge_container(_vector, start, middle, end);
	}
	else
		insert_vector(start, end);
}

void PmergeMe::insert_vector(int start, int end){
	int	j;
	int	temp;

	for (int i = start; i < (end - 1); ++i)
	{
		j = i + 1;
		temp = _vector[j];
		while (j > start && _vector[j - 1] > temp)
		{
			_vector[j] = _vector[j - 1];
			--j;
		}
		_vector[j] = temp;
	}
}

//LIST SORT

void PmergeMe::sort_list(int start, int end){
	
	if ((end - start) > 5){
		int middle = ((start + end) / 2);
		
		sort_list(start, middle);
		sort_list((middle + 1), end);
		
		merge_container(_list, start, middle, end);
	}
	else
		insert_list(start, end);
}

void PmergeMe::insert_list(int start, int end){
	int n = end - start - 1;

	for (int i = 0; i < n; ++i)
	{
		std::list<int>::iterator begin = _list.begin();
		std::advance(begin, start);
		std::list<int>::iterator begin_index = begin;
		std::advance(begin_index, i);
		std::list<int>::iterator limit = begin_index;
		std::advance(limit, n - i);
		std::list<int>::iterator iter = begin_index;
	
		int temp = *begin_index;
		while (iter != begin && *std::prev(iter) > temp)
			--iter;

		if (iter == begin_index)
			continue ;

		_list.splice(iter, _list, begin_index);
	}
}

std::vector<std::string>	PmergeMe::split_vectors(std::string str, char delimiter){
	std::vector<std::string>	ret;
	std::stringstream ss(str);
	std::string token;

	while(std::getline(ss, token, delimiter))
		ret.push_back(token);
	return (ret);
}

bool PmergeMe::is_string_digit(const std::string& str){
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

bool PmergeMe::is_string_int(const std::string& str){
	std::istringstream value(str);
	int temp;

	_temp = 0;
	value >> temp;
	if (temp >= INT_MAX) {
            return false;
    }
	_temp = temp;
    return true;
}

void	PmergeMe::print_vector(){
	for(size_t i = 0; i < _vector.size() - 1; i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::print_list(){
	std::list<int>::iterator it;
	for(it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int PmergeMe::parse_input(std::string input){
	std::vector<std::string> temp = split_vectors(input, ' ');
	
	for (size_t i = 0; i < temp.size(); i++){
		if (is_string_digit(temp[i]) == false)
			throw std::runtime_error("Error: Bad input: " + temp[i]);
	}
	for (size_t i = 0; i < temp.size(); i++){
		if (is_string_int(temp[i]) == false)
			throw std::runtime_error("Error: Bad input: " + temp[i]);
		_vector.push_back(_temp);
		_list.push_back(_temp);
		_size++;
	}

	return (0);
}


PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if(this != &other){
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return(*this);
}