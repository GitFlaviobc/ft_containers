/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* type_traits.hpp                                       :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/15 15:43:23 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/10 18:12:26 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	// - used to create the typedef false/true types.
	template <typename T, T v>
	struct integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;

		static const T	value = v;

		operator value_type() {
			return (value);
		}
	};

	// -true/false types
	typedef integral_constant<bool, false>	false_type;
	typedef integral_constant<bool, true>	true_type;

	// -is_integral General Case, used if no specialization is match
	template <typename T>
	struct is_integral : false_type {};

	// -Specializations, all the types on "< >" will return true_type when used is_integral
	template<>
	struct is_integral<bool> : true_type {};

	template<>
	struct is_integral<char> : true_type {};

	template<>
	struct is_integral<wchar_t> : true_type {};

	template<>
	struct is_integral<signed char> : true_type {};

	template<>
	struct is_integral<short int> : true_type {};

	template<>
	struct is_integral<int> : true_type {};

	template<>
	struct is_integral<long int> : true_type {};

	template<>
	struct is_integral<unsigned char> : true_type {};

	template<>
	struct is_integral<unsigned short int> : true_type {};

	template<>
	struct is_integral<unsigned int> : true_type {};

	template<>
	struct is_integral<unsigned long int> : true_type {};


	// -enable_if General case
	template <bool, typename T = void>
	struct enable_if {};

	// -Partial specialiaztion for true. Partial because it has """parameters""" inside < >
	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// -Const type
	template <bool isConst, typename isFalse, typename isTrue>
	struct chooseConst {};

	template <typename isFalse, typename isTrue>
	struct chooseConst<false, isFalse, isTrue> {
		typedef isFalse type;
	};

	template <typename isFalse, typename isTrue>
	struct chooseConst<true, isFalse, isTrue> {
		typedef isTrue type;
	};
}
#endif
