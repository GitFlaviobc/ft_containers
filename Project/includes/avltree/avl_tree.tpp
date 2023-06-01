/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* avl_tree.tpp                                          :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/12/07 10:31:09 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/10 16:44:13 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef AVL_TREE_TPP
#define AVL_TREE_TPP

#include "avl_tree.hpp"

namespace ft {
	// -Avl Logic Methods
	template <class Key, class T, class Compare, class Alloc>
	typename avl_tree<Key, T, Compare, Alloc>::nodeptr avl_tree<Key, T, Compare, Alloc>::createNode(const value_type &pair) {
		avl_node	*newNode = _allocNode.allocate(1);

		_allocPair.construct(&newNode->content, pair);
		newNode->parent = 0;
		newNode->left = 0;
		newNode->right = 0;

		return newNode;
	}

	template <class Key, class T, class Compare, class Alloc>
	void avl_tree<Key, T, Compare, Alloc>::deallocateNode(avl_node *del) {
		_allocPair.destroy(&del->content);
		_allocNode.deallocate(del, 1);
		return ;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool avl_tree<Key, T, Compare, Alloc>::deleteNode(avl_node *deletePos, key_type key) {
		avl_node	*balanceNode = 0;
		avl_node	*del = searchNode(deletePos, key);

		if (!del)
			return false;
		if (!del->parent) {
			if (del->left == _lastElem && del->right == _lastElem) {
				_root = _lastElem;
				_lastElem->left = _lastElem;
				_lastElem->right = _lastElem;
			}
			else if (del->left && del->right == _lastElem) {
				balanceNode = del->parent;
				_root = del->left;
				del->left->parent = 0;
				_lastElem->left = del->left;
				del->left->right = _lastElem;
			}
			else if (del->left == _lastElem && del->right) {
				balanceNode = del->parent;
				_root = del->right;
				del->right->parent = 0;
				_lastElem->right = del->right;
			del->right->left = _lastElem;
			}
			else {
				avl_node* maxNode = searchMaxNode(del->left);
				_allocPair.destroy(&del->content);
				_allocPair.construct(&del->content, maxNode->content);
				return deleteNode(del->left, maxNode->content.first);
			}
		}
		else if ((!del->left || del->left == _lastElem) && (!del->right || del->right == _lastElem)) {
			balanceNode = del->parent;
			avl_node* linkToParent = 0;
			if (del->left == _lastElem || del->right == _lastElem) {
				linkToParent = _lastElem;
				if (del->content.first <= del->parent->content.first)
					_lastElem->right = del->parent;
				else
					_lastElem->left = del->parent;
			}
			if (del->content.first <= del->parent->content.first)
				del->parent->left = linkToParent;
			else
				del->parent->right = linkToParent;
		}
		else if ((del->left && del->left != _lastElem) && (!del->right || del->right == _lastElem)) {
			balanceNode = del->parent;
			if (del->content.first <= del->parent->content.first)
				del->parent->left = del->left;
			else
				del->parent->right = del->left;
			del->left->parent = del->parent;
			if (del->right == _lastElem) {
				_lastElem->left = del->left;
				del->left->right = _lastElem;
			}
		}
		else if ((!del->left || del->left == _lastElem) && del->right && del->right != _lastElem) {
			balanceNode = del->parent;
			if (del->content.first <= del->parent->content.first)
				del->parent->left = del->right;
			else
				del->parent->right = del->right;
			del->right->parent = del->parent;
			if (del->left == _lastElem) {
				_lastElem->right = del->right;
				del->right->left = _lastElem;
			}
		}
		else {
			avl_node* maxNode = searchMaxNode(del->left);
			_allocPair.destroy(&del->content);
			_allocPair.construct(&del->content, maxNode->content);
			return deleteNode(del->left, maxNode->content.first);
		}
		balanceTheTree(&_root, balanceNode);
		deallocateNode(del);
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename avl_tree<Key, T, Compare, Alloc>::nodeptr avl_tree<Key, T, Compare, Alloc>::insertNode(avl_node *insertPos, const value_type &pair) {
		if (_root == _lastElem) {
			_root = createNode(pair);
			_root->left = _lastElem;
			_root->right = _lastElem;
			_lastElem->left = _root;
			_lastElem->right = _root;
			return _root;
		}
		if (insertPos->content.first == pair.first)
			return 0;
		if (insertPos->content.first > pair.first &&  insertPos->left && insertPos->left != _lastElem)
			return insertNode(insertPos->left, pair);
		else if (insertPos->content.first < pair.first && insertPos->right && insertPos->right != _lastElem)
			return insertNode(insertPos->right, pair);
		avl_node *newNode = createNode(pair);
		if (insertPos->content.first > newNode->content.first && !insertPos->left)
			insertPos->left = newNode;
		else if (insertPos->content.first < newNode->content.first && !insertPos->right)
			insertPos->right = newNode;
		else if (insertPos->left && insertPos->content.first > newNode->content.first) {
			newNode->left = _lastElem;
			_lastElem->right = newNode;
			insertPos->left = newNode;
		}
		else if (insertPos->right && insertPos->content.first < newNode->content.first) {
			newNode->right = _lastElem;
			_lastElem->left = newNode;
			insertPos->right = newNode;
		}
		newNode->parent = insertPos;
		balanceTheTree(&_root, newNode);
		return newNode;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename avl_tree<Key, T, Compare, Alloc>::nodeptr avl_tree<Key, T, Compare, Alloc>::searchNode(avl_node *root, key_type key) const {
		if (!root || root == _lastElem)
			return 0;
		if (!_comp(root->content.first, key) && !_comp(key, root->content.first))
			return root;
		if (root->content.first > key && root->left && root->left != _lastElem)
			return searchNode(root->left, key);
		else if (root->content.first < key && root->right && root->right != _lastElem)
			return searchNode(root->right, key);
		return 0;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename avl_tree<Key, T, Compare, Alloc>::nodeptr avl_tree<Key, T, Compare, Alloc>::searchMaxNode(avl_node *root) const {
		if (root->right && root->right != _lastElem)
			return searchMaxNode(root->right);
		return root;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename avl_tree<Key, T, Compare, Alloc>::nodeptr avl_tree<Key, T, Compare, Alloc>::searchMinNode(avl_node *root) const {
		if (root->left && root->left != _lastElem)
			return searchMinNode(root->left);
		return root;
	}

	// -Avl Private Methods
	template <class Key, class T, class Compare, class Alloc>
	int avl_tree<Key, T, Compare, Alloc>::heightTree(avl_node *root, int height) {
		if (!root || root == _lastElem)
			return height - 1;
		int leftHeight = heightTree(root->left, height + 1);
		int rightHeight = heightTree(root->right, height + 1);
		return leftHeight > rightHeight ? leftHeight : rightHeight;
	}

	template <class Key, class T, class Compare, class Alloc>
	void avl_tree<Key, T, Compare, Alloc>::balanceTheTree(avl_node **root, avl_node *node) {
		while (node) {
			int balance;
			
			if ((balance = balanceOfSubtrees(node)) < -1 && balanceOfSubtrees(node->right) < 0)
				rotateLeft(root, node);
			else if (balance > 1 && balanceOfSubtrees(node->left) > 0)
				rotateRight(root, node);
			else if (balance < -1 && balanceOfSubtrees(node->right) >= 0) {
				rotateRight(root, node->right);
				rotateLeft(root, node);
			}
			else if (balance > 1 && balanceOfSubtrees(node->left) <= 0) {
				rotateLeft(root, node->left);
				rotateRight(root, node);
			}
			node = node->parent;
		}
		return ;
	}

	template <class Key, class T, class Compare, class Alloc>
	int avl_tree<Key, T, Compare, Alloc>::balanceOfSubtrees(avl_node *node) {
		if (!node)
			return 0;
		return heightTree(node->left, 1) - heightTree(node->right, 1);
	}

	template <class Key, class T, class Compare, class Alloc>
	void avl_tree<Key, T, Compare, Alloc>::rotateRight(avl_node **root, avl_node *nodeGoingDown) {
		avl_node *nodeGoingUp = nodeGoingDown->left;

		nodeGoingDown->left = nodeGoingUp->right;
		if (nodeGoingUp->right)
			nodeGoingUp->right->parent = nodeGoingDown;
		nodeGoingUp->right = nodeGoingDown;
		nodeGoingUp->parent = nodeGoingDown->parent;
		if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
			nodeGoingDown->parent->left = nodeGoingUp;
		else if (nodeGoingDown->parent)
			nodeGoingDown->parent->right = nodeGoingUp;
		nodeGoingDown->parent = nodeGoingUp;
		if (!nodeGoingUp->parent)
			*root = nodeGoingUp;
		return ;
	}

	template <class Key, class T, class Compare, class Alloc>
	void avl_tree<Key, T, Compare, Alloc>::rotateLeft(avl_node **root, avl_node *nodeGoingDown) {
		avl_node *nodeGoingUp = nodeGoingDown->right;

		nodeGoingDown->right = nodeGoingUp->left;
		if (nodeGoingUp->left)
			nodeGoingUp->left->parent = nodeGoingDown;
		nodeGoingUp->left = nodeGoingDown;
		nodeGoingUp->parent = nodeGoingDown->parent;
		if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
			nodeGoingDown->parent->left = nodeGoingUp;
		else if (nodeGoingDown->parent)
			nodeGoingDown->parent->right = nodeGoingUp;
		nodeGoingDown->parent = nodeGoingUp;
		if (!nodeGoingUp->parent)
			*root = nodeGoingUp;
		return ;
	}
}

#endif
