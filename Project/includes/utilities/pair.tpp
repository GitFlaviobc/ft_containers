/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* pair.tpp                                              :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/13 21:18:41 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/11/16 09:56:13 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef PAIR_TPP
#define PAIR_TPP

#include "pair.hpp"

namespace ft {
	// -Constructors
	template <typename T1, typename T2>
	pair<T1, T2>::pair(void) : first(), second() {
		return ;
	}

	template <typename T1, typename T2>
	pair<T1, T2>::pair(const T1 &a, const T2 &b) : first(a), second(b) {
		return ;
	}

	template <typename T1, typename T2>
	template <class U, class V>
	pair<T1, T2>::pair(const pair<U, V> &obj) : first(obj.first), second(obj.second) {
		return ;
	}

	// -Destructors
	template <typename T1, typename T2>
	pair<T1, T2>::~pair(void) {
		return ;
	}

	// -Operators
	template <typename T1, typename T2>
	pair<T1, T2> &pair<T1, T2>::operator=(pair<T1, T2> const &rhs) {
		if (this != &rhs) {
			this->first = rhs.first;
			this->second = rhs.second;
		}
		return (*this);
	}

	template <class T1, class T2>
	inline bool	operator==(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (x.first == y.first && x.second == y.second);
	}

	template <class T1, class T2>
	inline bool	operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (!(x == y));
	}

	template <class T1, class T2>
	inline bool	operator<(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	}

	template <class T1, class T2>
	inline bool	operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (!(y < x));
	}

	template <class T1, class T2>
	inline bool	operator>(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (y < x);
	}

	template <class T1, class T2>
	inline bool	operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
		return (!(x < y));
	}

	// -Functions
	template<class T1, class T2>
	inline ft::pair<T1, T2> make_pair(T1 x, T2 y) {
		return (ft::pair<T1, T2>(x, y));
	}
}

#endif
