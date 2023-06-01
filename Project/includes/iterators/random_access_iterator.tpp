/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* random_access_iterator.tpp                            :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/17 15:03:20 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/11/20 11:25:48 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_TPP
#define RANDOM_ACCESS_ITERATOR_TPP

#include "random_access_iterator.hpp"

namespace ft {
	// -Constructors
	template <typename T>
	random_access_iterator<T>::random_access_iterator(void) : _current(NULL) {
		return ;
	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(pointer ptr) : _current(ptr) {
		return ;
	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator &iter) {
		*this = iter;
	}

	// -Destructor
	template <typename T>
	random_access_iterator<T>::~random_access_iterator(void) {
		return ;
	}

	// - Operators
	template <typename T>
	random_access_iterator<T> &random_access_iterator<T>::operator=(const random_access_iterator &rhs) {
		if (this != &rhs) {
			this->_current = rhs._current;
		}
		return (*this);
	}

	template <typename T>
	bool random_access_iterator<T>::operator==(const iterator &rhs) {
		return (this->_current == rhs._current);
	}
	
	template <typename T>
	bool random_access_iterator<T>::operator!=(const iterator &rhs) {
		return (this->_current != rhs._current);
	}
	
	template <typename T>
	bool random_access_iterator<T>::operator>(const iterator &rhs) {
		return (this->_current > rhs._current);
	}
	
	template <typename T>
	bool random_access_iterator<T>::operator>=(const iterator &rhs) {
		return (this->_current >= rhs._current);
	}
	
	template <typename T>
	bool random_access_iterator<T>::operator<(const iterator &rhs) {
		return (this->_current < rhs._current);
	}
	
	template <typename T>
	bool random_access_iterator<T>::operator<=(const iterator &rhs) {
		return (this->_current <= rhs._current);
	}

	template <typename T>
	random_access_iterator<T> &random_access_iterator<T>::operator++(void) {
		this->_current++;
		return (*this);
	}
	
	template <typename T>
	random_access_iterator<T> &random_access_iterator<T>::operator--(void) {
		this->_current--;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T> random_access_iterator<T>::operator++(int) {
		return (random_access_iterator(_current++));
	}

	template <typename T>
	random_access_iterator<T> random_access_iterator<T>::operator--(int) {
		return (random_access_iterator(_current--));
	}

	template <typename T>
	random_access_iterator<T> random_access_iterator<T>::operator+(int rhs) {
		return (iterator(this->_current + rhs));
	}

	template <typename T>
	random_access_iterator<T> random_access_iterator<T>::operator-(int rhs) {
		return (iterator(this->_current - rhs));
	}

	template <typename T>
	random_access_iterator<T> &random_access_iterator<T>::operator+=(int rhs) {
		this->_current += rhs;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T> &random_access_iterator<T>::operator-=(int rhs) {
		this->_current -= rhs;
		return (*this);
	}

	template <typename T>
	int random_access_iterator<T>::operator+(const iterator &rhs) {
		return (this->_current + rhs._current);
	}

	template <typename T>
	int random_access_iterator<T>::operator-(const iterator &rhs) {
		return (this->_current - rhs._current);
	}

	template <typename T>
	typename random_access_iterator<T>::reference random_access_iterator<T>::operator[](const int n) const {
		return (this->_current[n]);
	}

	template <typename T>
	typename random_access_iterator<T>::value_type random_access_iterator<T>::operator*(void) const {
		return (*this->_current);
	}
	
	template <typename T>
	typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->(void) {
		return (this->_current);
	}

	// -Method
	template <typename T>
	typename random_access_iterator<T>::pointer random_access_iterator<T>::base(void) const {
		return (this->_current);
	}

	// -Functions
	template<typename T>
	inline bool operator==(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename T>
	inline bool operator!=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	inline bool operator<(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	inline bool operator<=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T>
	inline bool operator>(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	inline bool operator>=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator==(const ft::random_access_iterator<T_R> &lhs, const ft::random_access_iterator<T_L> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator!=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator<(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator<=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator>(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator>=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T_L, typename T_R>
	inline typename random_access_iterator<T_L>::difference_type operator-(const random_access_iterator<T_L> &lhs, const random_access_iterator<T_R> &rhs) {
		return (lhs.base() - rhs.base());
	}
}

#endif
