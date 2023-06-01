#ifndef REVERSE_ITERATOR_TREE_HPP
#define REVERSE_ITERATOR_TREE_HPP

#define TREE_REV_IT_TEMPL	typename Key, \
							typename T, \
							typename Compare, \
							typename Node, \
							bool B
#define TREE_REV_IT_CLASS	reverse_tree_iterator<Key, T, Compare, Node, B>

#include "iterator_tree.hpp"

namespace ft {
	template<typename Key, typename T, typename Compare, typename Node, bool B>
	class reverse_tree_iterator {
		public:
			// -Typedefs
			typedef T										mapped_type;
			typedef Node*									nodePtr;
			typedef Key										key_type;
			typedef Compare									key_compare;
			typedef long int								difference_type;
			typedef size_t									size_type;
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef typename chooseConst<B, value_type&, const value_type&>::type	reference;
			typedef typename chooseConst<B, value_type*, const value_type*>::type	pointer;

			// -Constructors
			reverse_tree_iterator(nodePtr node = 0, nodePtr lastElem = 0, const key_compare &comp = key_compare());
			reverse_tree_iterator(const reverse_tree_iterator<Key, T, Compare, Node, false> &copy);
			explicit reverse_tree_iterator(iterator_tree<Key, T, Compare, Node, false> copy);

			// -Destructors
			~reverse_tree_iterator(void);

			// -Operators
			reverse_tree_iterator	&operator=(const reverse_tree_iterator &rhs);
			reverse_tree_iterator	&operator++(void);
			reverse_tree_iterator	operator++(int);
			reverse_tree_iterator	&operator--(void);
			reverse_tree_iterator	operator--(int);
			reference				operator*(void) const;
			pointer					operator->(void) const;
			bool					operator==(const reverse_tree_iterator &it) const;
			bool					operator!=(const reverse_tree_iterator &it) const;

			// -Getters
			nodePtr		getNonConstNode(void) const;
			nodePtr		getNonConstLastElem(void) const;
			key_compare	getCompare(void) const;

		private:
			nodePtr		_node;
			nodePtr		_lastElem;
			key_compare	_comp;

			// -Private Methods
			nodePtr	searchMaxNode(nodePtr root);
			nodePtr searchMinNode(nodePtr root);
	};
}

#include "reverse_iterator_tree.tpp"

#endif
