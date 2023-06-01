/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* vector.hpp                                            :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/07 15:11:59 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/08 16:45:11 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			// -Typedefs
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename Alloc::reference					reference;
			typedef typename Alloc::const_reference				const_reference;
			typedef typename Alloc::pointer						pointer;
			typedef typename Alloc::const_pointer				const_pointer;
			typedef ft::random_access_iterator<pointer>			iterator;
			typedef ft::random_access_iterator<const_pointer>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

			// -Constructors
			vector(const allocator_type &alloc = allocator_type());
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			vector(vector const &rhs);

			// -Destructor
			~vector(void);

			// -Operators
			vector &operator=(const vector &rhs);
			
			// -Capacity Methods
			size_type	size(void) const;
			size_type	max_size(void) const;
			void		resize(size_type n);
			void		resize(size_type n, T val);
			size_type	capacity(void) const;
			bool		empty(void) const;
			void		reserve(size_type new_cap);

			// -Element Access Methods
			const_reference		operator[](size_type n) const;
			reference			operator[](size_type n);
			const_reference		at(size_type n) const;
			reference			at(size_type n);
			const_reference		front(void) const;
			reference			front(void);
			const_reference		back(void) const;
			reference			back(void);
			value_type*			data(void);
			const value_type*	data(void) const;

			// -Modifiers Methods
			template <class InputIterator>
			void		assign(InputIterator first, InputIterator last);
			void		assign(size_t count, const T &value);
			void		push_back(T const &x);
			void		pop_back(void);
			iterator	insert(iterator pos, T const &value);
			iterator	insert(iterator pos, size_t count, T const &value);
			iterator	insert(iterator pos, iterator begin, iterator end);
			iterator	erase(iterator pos);
			iterator	erase(iterator begin, iterator end);
			void		swap(vector &vec);
			void		clear(void);

			// -Iterators Methods
			iterator				begin(void);
			iterator				end(void);
			const_iterator			cbegin(void) const;
			const_iterator			cend(void) const;
			reverse_iterator		rbegin(void);
			reverse_iterator		rend(void);
			const_reverse_iterator	crbegin(void) const;
			const_reverse_iterator	crend(void) const;

			// -Getter
			allocator_type	get_allocator(void) const;

		protected:
			T*					_data;
			unsigned int		_size;
			unsigned int		_capacity;
			Alloc				_alloc;
	};
	// -Functions
	template <class T, class Alloc>
	inline bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	inline bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	inline bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	inline bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	inline bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template <class T, class Alloc>
	inline bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	template<class T, class Alloc>
	inline void	swap(vector<T, Alloc> lhs, vector <T, Alloc> rhs);
}

#include "vector.tpp"

#endif
