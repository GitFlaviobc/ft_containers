/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* avl_tree.hpp                                          :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/12/07 10:31:06 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/10 10:08:09 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <memory>
#include "algorithm.hpp"
#include "pair.hpp"
#include "avl_node.hpp"

namespace ft {
	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	struct avl_tree {
		public:
			// -Typedefs
			typedef T										mapped_type;
			typedef ft::Node<Key, T>						avl_node;
			typedef ft::Node<Key, T>*						nodeptr;
			typedef Key										key_type;
			typedef Alloc									allocator_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type>	value_type;
		
			// -Avl Attributes
			nodeptr						_root;          // Pointer to the first element of the tree (root)
			nodeptr						_lastElem;      // Pointer to the last elem of the tree
			allocator_type				_allocPair;     // Copy of allocator_type object
			key_compare					_comp;          // Copy of comp key_compare predicate
			std::allocator<avl_node>	_allocNode;     // Node's allocator

			// -Avl Logic Methods
			nodeptr	createNode(const value_type &pair);
			void	deallocateNode(avl_node *del);
			bool	deleteNode(avl_node *deletePos, key_type key);
			nodeptr	insertNode(avl_node *insertPos, const value_type &pair);
			nodeptr	searchNode(avl_node *root, key_type key) const;
			nodeptr	searchMaxNode(avl_node *root) const;
			nodeptr	searchMinNode(avl_node *root) const;
			
		private:
			// -Avl Private Methods
			int		heightTree(avl_node *root, int height);
			void	balanceTheTree(avl_node **root, avl_node *node);
			int		balanceOfSubtrees(avl_node *node);
			void	rotateRight(avl_node **root, avl_node *nodeGoingDown);
			void	rotateLeft(avl_node **root, avl_node *nodeGoingDown);
	};
}

#include "avl_tree.tpp"

#endif
