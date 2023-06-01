/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* random_access_iterator.hpp                            :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/17 15:03:17 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/10 18:15:36 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T> {
		public:
			// -Typedefs
			typedef T														iterator;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;

			// -Constructors
			random_access_iterator(void);
			random_access_iterator(pointer ptr);
			random_access_iterator(const random_access_iterator &iter);

			// -Destructor
			~random_access_iterator(void);

			// -Operators
			random_access_iterator		&operator=(const random_access_iterator &rhs);
			bool				operator==(const iterator &rhs);
			bool				operator!=(const iterator &rhs);
			bool				operator>(const iterator &rhs);
			bool				operator>=(const iterator &rhs);
			bool				operator<(const iterator &rhs);
			bool				operator<=(const iterator &rhs);
			random_access_iterator		&operator++(void);
			random_access_iterator		&operator--(void);
			random_access_iterator		operator++(int);
			random_access_iterator		operator--(int);
			random_access_iterator		operator+(int rhs);
			random_access_iterator		operator-(int rhs);
			random_access_iterator		&operator+=(int rhs);
			random_access_iterator		&operator-=(int rhs);
			int					operator+(const iterator &rhs);
			int					operator-(const iterator &rhs);
			reference			operator[](const int n) const;
			value_type			operator*(void) const;
			pointer				operator->(void);

			// -Method
			pointer	base(void) const;

		protected:
			pointer	_current;
	};
	// -Functions
	template<typename T>
	inline bool operator==(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T>
	inline bool operator!=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T>
	inline bool operator<(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T>
	inline bool operator<=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T>
	inline bool operator>(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T>
	inline bool operator>=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator==(const ft::random_access_iterator<T_R> &lhs, const ft::random_access_iterator<T_L> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator!=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator<(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator<=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator>(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs);

	template<typename T_L, typename T_R>
	inline bool operator>=(const ft::random_access_iterator<T_L> &lhs, const ft::random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	inline typename random_access_iterator<T_L>::difference_type operator-(const random_access_iterator<T_L> &lhs, const random_access_iterator<T_R> &rhs);
}

#include "random_access_iterator.tpp"

#endif
