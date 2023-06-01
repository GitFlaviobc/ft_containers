#ifndef ITERATOR_TREE_TPP
#define ITERATOR_TREE_TPP

#include "iterator_tree.hpp"

namespace ft {
	// -Constructors
	template <TREE_IT_TEMPL>
	TREE_IT_CLASS::iterator_tree(nodePtr node, nodePtr lastElem, const key_compare &comp) : _node(node), _lastElem(lastElem), _comp(comp) {
		return ;
	}

	template <TREE_IT_TEMPL>
	TREE_IT_CLASS::iterator_tree(const iterator_tree<Key, T, Compare, Node, false> &copy) {
		*this = copy;
		return ;
	}

	// -Destructor
	template <TREE_IT_TEMPL>
	TREE_IT_CLASS::~iterator_tree(void) {
		return ;
	}

	// -Operators
	template <TREE_IT_TEMPL>
	TREE_IT_CLASS &TREE_IT_CLASS::operator=(const iterator_tree &rhs) {
		if (this != &rhs) {
			this->_node = rhs._node;
			this->_lastElem = rhs._lastElem;
			this->_comp = rhs._comp;
		}
		return (*this);
	}

	template <TREE_IT_TEMPL>
	TREE_IT_CLASS &TREE_IT_CLASS::operator++(void) {
		nodePtr	previousNode = _node;
		Node	*tmp = 0;

		if (_node == _lastElem) {
			_node = _lastElem->right;
			return (*this);
		}
		while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first)) {
			if (_node->right && (_node->right == _lastElem || 
					_comp(previousNode->content.first, _node->right->content.first))) {
				_node = _node->right;
				tmp = 0;
				if (_node != _lastElem && (tmp = searchMinNode(_node)))
					_node = tmp;
			}
			else {
				_node = _node->parent;
			}
		}
		return (*this);
	}

	template <TREE_IT_TEMPL>
	TREE_IT_CLASS TREE_IT_CLASS::operator++(int) {
		iterator_tree	res(*this);
		Node			*tmp = 0;

		if (_node == _lastElem) {
			_node = _lastElem->right;
			return (res);
		}
		while (_node != _lastElem && !_comp(res->first, _node->content.first)) {
			if (_node->right && (_node->right == _lastElem || 
					_comp(res->first, _node->right->content.first))) {
				_node = _node->right;
				tmp = 0;
				if (_node != _lastElem && (tmp = searchMinNode(_node)))
					_node = tmp;
			}
			else {
				_node = _node->parent;
			}
		}
		return (res);
	}

	template <TREE_IT_TEMPL>
	TREE_IT_CLASS &TREE_IT_CLASS::operator--(void) {
		nodePtr	previousNode = this->_node;
		Node	*tmp = 0;

		if (_node == _lastElem) {
			_node = _lastElem->left;
			return (*this);
		}
		while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first)) {
			if (_node->left && (_node->left == _lastElem || 
					_comp(_node->left->content.first, previousNode->content.first))) {
				_node = _node->left;
				tmp = 0;
				if (_node != _lastElem && (tmp = searchMaxNode(_node)))
					_node = tmp;
			}
			else {
				_node = _node->parent;
			}
		}
		return (*this);
	}

	template <TREE_IT_TEMPL>
	TREE_IT_CLASS TREE_IT_CLASS::operator--(int) {
		iterator_tree	res(*this);
		Node			*tmp = 0;

		if (_node == _lastElem) {
			_node = _lastElem->left;
			return (res);
		}
		while (_node != _lastElem && !_comp(_node->content.first, res->first)) {
			if (_node->left && (_node->left == _lastElem || 
					_comp(_node->left->content.first, res->first))) {
				_node = _node->left;
				tmp = 0;
				if (_node != _lastElem && (tmp = searchMaxNode(_node)))
					_node = tmp;
			}
			else {
				_node = _node->parent;
			}
		}
		return (res);
	}

	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::reference TREE_IT_CLASS::operator*(void) const {
		return (_node->content);
	}

	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::pointer TREE_IT_CLASS::operator->(void) const {
		return (&this->_node->content);
	}

	template <TREE_IT_TEMPL>
	bool TREE_IT_CLASS::operator==(const iterator_tree &it) const {
		return (it._node == this->_node);
	}

	template <TREE_IT_TEMPL>
	bool TREE_IT_CLASS::operator!=(const iterator_tree &it) const {
		return (it._node != this->_node);
	}

	// -Getters
	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::nodePtr TREE_IT_CLASS::getNode(void) const {
		return (this->_node);
	}

	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::nodePtr TREE_IT_CLASS::getLastElem(void) const {
		return (this->_lastElem);
	}

	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::key_compare TREE_IT_CLASS::getCompare(void) const {
		return (this->_comp);
	}

	// -Private Methods
	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::nodePtr TREE_IT_CLASS::searchMaxNode(nodePtr root) {
		if (root && root != this->_lastElem && root->right && root->right != this->_lastElem)
			return (searchMaxNode(root->right));
		return (root);
	}

	template <TREE_IT_TEMPL>
	typename TREE_IT_CLASS::nodePtr TREE_IT_CLASS::searchMinNode(nodePtr root) {
		if (root && root != this->_lastElem && root->left && root->left != this->_lastElem)
			return (searchMinNode(root->left));
		return (root);
	}
}

#endif
