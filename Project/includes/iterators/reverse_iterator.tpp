/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* reverse_iterator.tpp                                  :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/17 17:15:05 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/01 15:08:51 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
#define REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {
	// -Constructors
	template <typename T>
	reverse_iterator<T>::reverse_iterator(void) : _current(NULL) {
		return ;
	}

	template <typename T>
	reverse_iterator<T>::reverse_iterator(iterator_type iter) : _current(iter) {
		return;
	}

	template <typename T>
	reverse_iterator<T>::reverse_iterator(const reverse_iterator &iter) : _current(iter._current) {
		return ;
	}

	template <typename T>
	template <class Iter>
	reverse_iterator<T>::reverse_iterator(const reverse_iterator<Iter> &other) : _current(other.base()) {
		return ;
	}

	// -Destructor
	template <typename T>
	reverse_iterator<T>::~reverse_iterator(void) {
		return ;
	}

	// -Operators
	template <typename T>
	template <typename Iter>
	reverse_iterator<T> &reverse_iterator<T>::operator=(const reverse_iterator<Iter> &x) {
		_current = x.base();
		return (*this);
	}
	
	template <typename T>
	reverse_iterator<T> &reverse_iterator<T>::operator++(void) {
		this->_current--;
		return (*this);
	}

	template <typename T>
	reverse_iterator<T> &reverse_iterator<T>::operator--(void) {
		this->_current++;
		return (*this);
	}

	template <typename T>
	reverse_iterator<T> reverse_iterator<T>::operator++(int) {
		reverse_iterator temp = *this;
		this->_current--;
		return (temp);
	}

	template <typename T>
	reverse_iterator<T> reverse_iterator<T>::operator--(int) {
		reverse_iterator temp = *this;
		this->_current++;
		return (temp);
	}

	template <typename T>
	reverse_iterator<T> reverse_iterator<T>::operator+(difference_type n) {
		 return (reverse_iterator(base() - n));
	}

	template <typename T>
	reverse_iterator<T> reverse_iterator<T>::operator-(difference_type n) {
		return (reverse_iterator(base() + n));
	}

	template <typename T>
	reverse_iterator<T> &reverse_iterator<T>::operator+=(difference_type n) {
		this->_current -= n;
		return (*this);
	}

	template <typename T>
	reverse_iterator<T> &reverse_iterator<T>::operator-=(difference_type n) {
		this->_current += n;
		return (*this);
	}

	template <typename T>
	typename reverse_iterator<T>::reference reverse_iterator<T>::operator[](difference_type n) const {
		return (this->base()[n - 1]);
	}

	template <typename T>
	typename reverse_iterator<T>::value_type reverse_iterator<T>::operator*(void) const {
		T temp = this->_current;
		return (*temp);
	}

	template <typename T>
	typename reverse_iterator<T>::pointer reverse_iterator<T>::operator->(void) {
		return (&*(--iterator_type(_current)));
	}

	// -Method
	template <typename T>
	typename reverse_iterator<T>::iterator_type	reverse_iterator<T>::base(void) const {
		return (this->_current);
	}

	// -Functions
	template<typename T>
	inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename T>
	inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	inline bool operator<(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T>
	inline bool operator>(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator==(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator!=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator<(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator>(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator<=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T_L, typename T_R>
	inline bool operator>=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs) {
		return (lhs.base() >= rhs.base());
	}
}

#endif
