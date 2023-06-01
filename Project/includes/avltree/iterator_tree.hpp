#ifndef ITERATOR_TREE_HPP
#define ITERATOR_TREE_HPP

#define TREE_IT_TEMPL	typename Key, \
						typename T, \
						typename Compare, \
						typename Node, \
						bool B
#define TREE_IT_CLASS	iterator_tree<Key, T, Compare, Node, B>

#include <memory>
#include "pair.hpp"
#include "type_traits.hpp"

namespace ft {
	template <typename Key, typename T, typename Compare, typename Node, bool B>
	class iterator_tree {
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
			iterator_tree(nodePtr node = 0, nodePtr lastElem = 0, const key_compare &comp = key_compare());
			iterator_tree(const iterator_tree<Key, T, Compare, Node, false> &copy);

			// -Destructor
			~iterator_tree(void);

			// -Operators
			iterator_tree	&operator=(const iterator_tree &rhs);
			iterator_tree	&operator++(void);
			iterator_tree	operator++(int);
			iterator_tree	&operator--(void);
			iterator_tree	operator--(int);
			reference		operator*(void) const;
			pointer			operator->(void) const;
			bool			operator==(const iterator_tree &it) const;
			bool			operator!=(const iterator_tree &it) const;

			// -Getters
			nodePtr		getNode(void) const;
			nodePtr		getLastElem(void) const;
			key_compare	getCompare(void) const;

		private:
			nodePtr		_node;
			nodePtr		_lastElem;
			key_compare	_comp;
			
			// -Private Methods
			nodePtr	searchMaxNode(nodePtr root);
			nodePtr	searchMinNode(nodePtr root);
	};
}

#include "iterator_tree.tpp"

#endif
