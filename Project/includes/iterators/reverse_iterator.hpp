/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* reverse_iterator.hpp                                  :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/17 17:15:02 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/11/19 19:11:45 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <typename T>
	class reverse_iterator : public ft::iterator<
		typename ft::iterator_traits<T>::iterator_category,
		typename ft::iterator_traits<T>::value_type,
		typename ft::iterator_traits<T>::difference_type,
		typename ft::iterator_traits<T>::pointer,
		typename ft::iterator_traits<T>::reference> {
		public:
			// -Typedefs
			typedef T													iterator_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			// -Constructors
			reverse_iterator(void);
			reverse_iterator(iterator_type iter);
			reverse_iterator(const reverse_iterator &iter);
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &other);

			// -Destructor
			~reverse_iterator(void); 

			// -Operators
			template <typename Iter>
			reverse_iterator &operator=(const reverse_iterator<Iter> &x);
			reverse_iterator		&operator++(void);
			reverse_iterator		&operator--(void);
			reverse_iterator		operator++(int);
			reverse_iterator		operator--(int);
			reverse_iterator		operator+(difference_type n);
			reverse_iterator		operator-(difference_type n);
			reverse_iterator		&operator+=(difference_type n);
			reverse_iterator		&operator-=(difference_type n);
			reference				operator[](difference_type n) const;
			value_type				operator*(void) const;
			pointer					operator->(void);

			// -Method
			iterator_type	base(void) const;

		protected:
			iterator_type	_current;
	};
	// -Functions
	template<typename T>
	inline bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T>
	inline bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T>
	inline bool operator<(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T>
	inline bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T>
	inline bool operator>(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T>
	inline bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator==(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator!=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator<(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator>(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator<=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator>=(const reverse_iterator<T_L> &lhs, const reverse_iterator<T_R> &rhs);
}

#include "reverse_iterator.tpp"

#endif
