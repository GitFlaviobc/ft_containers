/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* pair.hpp                                              :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/13 21:18:38 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/11/26 12:35:43 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <typename T1, typename T2>
	struct pair {
		public:
			// -Typedefs
			typedef T1	first_type;
			typedef T2	seconde_type;

			// -Copies
			T1	first;
			T2	second;

			// -Constructors
			pair(void);
			pair(const T1 &a, const T2 &b);
			template <class U, class V>
			pair(const pair<U, V> &obj);
			
			// -Destructor
			~pair(void);

			// -Operators
			pair<T1, T2> &operator=(pair<T1, T2> const &rhs);
	};

	// -Operators
	template <class T1, class T2>
	inline bool	operator==(const pair<T1, T2> &x, const pair<T1, T2> &y);

	template <class T1, class T2>
	inline bool	operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y);

	template <class T1, class T2>
	inline bool	operator<(const pair<T1, T2> &x, const pair<T1, T2> &y);

	template <class T1, class T2>
	inline bool	operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y);

	template <class T1, class T2>
	inline bool	operator>(const pair<T1, T2> &x, const pair<T1, T2> &y);

	template <class T1, class T2>
	inline bool	operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y);

	// -Functions
	template<class T1, class T2>
	inline ft::pair<T1, T2> make_pair(T1 x, T2 y);
}

#include "pair.tpp"

#endif
