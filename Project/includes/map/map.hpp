/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* map.hpp                                               :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/26 09:57:33 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/10 17:34:19 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "reverse_iterator_tree.hpp"
#include "iterator_tree.hpp"
#include "avl_tree.hpp"
#include "avl_node.hpp"
#include "algorithm.hpp"
#include "pair.hpp"

#define MAP_TEMPLATE	class Key, \
						class T, \
						class Compare, \
						class Alloc

#define MAP_CLASS map<Key, T, Compare, Alloc>

namespace ft {
	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			// -Typedefs
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef size_t																size_type;
			typedef T*																	pointer;
			typedef T&																	reference;
			typedef const T*															const_pointer;
			typedef const T&															const_reference;
			typedef long int															difference_type;
			typedef typename ft::Node<Key, T>											Node;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef typename ft::avl_tree<Key, T, Compare, Alloc>						avl_tree;
			typedef typename ft::iterator_tree<Key, T, Compare, Node, false>			iterator;
			typedef typename ft::iterator_tree<Key, T, Compare, Node, true>				const_iterator;
			typedef typename ft::reverse_tree_iterator<Key, T, Compare, Node, false>	reverse_iterator;
			typedef typename ft::reverse_tree_iterator<Key, T, Compare, Node, true>		const_reverse_iterator;

			class value_compare {
				friend class map;
				protected:
					key_compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool        result_type;
					typedef value_type  first_argument_type;
					typedef value_type  second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
			// -Constructors
			map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			map(const map &copy);

			// -Destructor
			~map(void);
			
			// -Operators
			map	&operator=(const map &rhs);

			// -Iterators methods
			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			// -Capacity Methods
			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			// -Element access Methods
			mapped_type	&operator[](const key_type &k);
			mapped_type	&at(const key_type &k);

			// -Modifiers Methods
			template <class InputIterator>
			void					insert(InputIterator first, InputIterator last);
			ft::pair<iterator,bool>	insert(const value_type &val);
			iterator				insert(iterator position, const value_type &val);
			size_type				erase(const key_type &k);
			void					erase(iterator position);
			void					erase(iterator first, iterator last);
			void					swap(map &rhs);
			void					clear(void);

			// -Other Methods
			key_compare							key_comp(void) const;
			value_compare						value_comp(void) const;
			iterator							find(const key_type &k);
			const_iterator						find(const key_type &k) const;
			size_type							count(const key_type &k) const;
			iterator							lower_bound(const key_type &k);
			const_iterator						lower_bound(const key_type &k) const;
			iterator							upper_bound(const key_type &k);
			const_iterator						upper_bound(const key_type &k) const;
			pair<iterator,iterator>				equal_range(const key_type &k);
			pair<const_iterator,const_iterator>	equal_range(const key_type &k) const;

		private:
			avl_tree	_tree;
			size_type	_size;
			key_compare	_comp;

			// -Private Method
			template <typename U>
			void swap(U &a, U &b);
	};
	// -Operator Functions
	template<MAP_TEMPLATE>
	bool	operator==(const MAP_CLASS &lhs, const MAP_CLASS &rhs);

	template<MAP_TEMPLATE>
	bool	operator!=(const MAP_CLASS &lhs, const MAP_CLASS &rhs);
	
	template<MAP_TEMPLATE>
	bool	operator<(const MAP_CLASS &lhs, const MAP_CLASS &rhs);

	template<MAP_TEMPLATE>
	bool	operator<=(const MAP_CLASS &lhs, const MAP_CLASS &rhs);

	template<MAP_TEMPLATE>
	bool	operator>(const MAP_CLASS &lhs, const MAP_CLASS &rhs);

	template<MAP_TEMPLATE>
	bool	operator>=(const MAP_CLASS &lhs, const MAP_CLASS &rhs);

	template<MAP_TEMPLATE>
	void	swap(MAP_CLASS &lhs, MAP_CLASS &rhs);
}

#include "map.tpp"

#endif
