/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* map.tpp                                               :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/26 09:57:36 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/07 13:51:00 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef MAP_TPP
#define MAP_TPP

#include "map.hpp"

namespace ft {
	// -Constructors
	template<MAP_TEMPLATE>
	MAP_CLASS::map(const key_compare &comp, const allocator_type &alloc) : _tree(), _size(0), _comp(comp) {
		_tree._allocPair = alloc;
		_tree._lastElem = _tree.createNode(ft::pair<const key_type, mapped_type>());
		_tree._root = _tree._lastElem;
		_tree._lastElem->left = _tree._lastElem;
		_tree._lastElem->right = _tree._lastElem;
		return ;
	}

	template<MAP_TEMPLATE>
	MAP_CLASS::map(const map &copy) {
		*this = copy;
		return ;
	}

	// -Destructor
	template<MAP_TEMPLATE>
	MAP_CLASS::~map(void) {
		clear();
		_tree.deallocateNode(_tree._lastElem);
		return ;
	}

	// -Operators
	template<MAP_TEMPLATE>
	MAP_CLASS &MAP_CLASS::operator=(const map &rhs) {
		map tmp(rhs);

		this->swap(rhs);
		return (*this);
	}

	// -Iterators methods
	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::begin(void) {
		return ((iterator(_tree._lastElem->right, _tree._lastElem, _comp)));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_iterator MAP_CLASS::begin(void) const {
		return ((const_iterator(_tree._lastElem->right, _tree._lastElem, _comp)));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::end(void) {
		return ((iterator(_tree._lastElem, _tree._lastElem, _comp)));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_iterator MAP_CLASS::end(void) const {
		return (const_iterator(_tree._lastElem, _tree._lastElem, _comp));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::reverse_iterator MAP_CLASS::rbegin(void) {
		return (reverse_iterator(_tree._lastElem->left, _tree._lastElem, _comp));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rbegin(void) const {
		return (const_reverse_iterator(_tree._lastElem->left, _tree._lastElem, _comp));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::reverse_iterator MAP_CLASS::rend(void) {
		return (reverse_iterator(_tree._lastElem, _tree._lastElem, _comp));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rend(void) const {
		return (const_reverse_iterator(_tree._lastElem, _tree._lastElem, _comp));
	}

	// -Capacity Methods
	template<MAP_TEMPLATE>
	bool MAP_CLASS::empty(void) const {
		return (this->_size == 0);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::size_type MAP_CLASS::size(void) const {
		return (this->_size);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::size_type MAP_CLASS::max_size(void) const {
		return (this->_tree._allocPair.max_size());
	}

	// -Element access Methods
	template<MAP_TEMPLATE>
	typename MAP_CLASS::mapped_type &MAP_CLASS::operator[](const key_type &k) {
		Node* tmp = _tree.searchNode(_tree._root, k);

		if (tmp)
			return (tmp->content.second);
		value_type val = make_pair<key_type, mapped_type>(k, mapped_type());
		return (this->_tree.insertNode(_tree._root, val)->content.second);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::mapped_type &MAP_CLASS::at(const key_type &k) {
		Node* tmp = _tree.searchNode(_tree._root, k);

		if (tmp)
			return (tmp->content.second);
		else
			throw std::out_of_range("Not found");
	}

	// -Modifiers Methods
	template<MAP_TEMPLATE>
	template <class InputIterator>
	void MAP_CLASS::insert(InputIterator first, InputIterator last) {
		while (first != last)
			insert(*first++);
		return ;
	}

	template<MAP_TEMPLATE>
	ft::pair<typename MAP_CLASS::iterator, bool>
	MAP_CLASS::insert(const value_type &val) {
		Node* elemIsPresent = _tree.searchNode(_tree._root, val.first);

		if (elemIsPresent)
			return (ft::pair<iterator, bool>(iterator(elemIsPresent, _tree._lastElem, _comp), false));
		++_size;
		return (ft::pair<iterator, bool>(iterator(_tree.insertNode(_tree._root, val), _tree._lastElem, _comp), true));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::insert(iterator position, const value_type& val) {
		if (position->first > val.first) {
			iterator prev(position);
			--prev;
			while (prev != end() && prev->first >= val.first) {
				--position;
				--prev;
			}
		}
		else if (position->first < val.first) {
			iterator next(position);
			++next;
			while (next != end() && next->first <= val.first) {
				++position;
				++next;
			}
		}
		if (position != end() && val.first == position->first)
			return (position);
		++_size;
		return (iterator(_tree.insertNode(position.getNode(), val), _tree._lastElem, _comp));
	}

	template<MAP_TEMPLATE>
	void MAP_CLASS::erase(iterator position) {
		_tree.deleteNode(position.getNode(), position->first);
		--_size;
		return ;
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::size_type MAP_CLASS::erase(const key_type &k) {
		size_type ret = _tree.deleteNode(_tree._root, k);
		_size -= ret;
		return (ret);
	}

	template<MAP_TEMPLATE>
	void MAP_CLASS::erase(iterator first, iterator last) {
		while (first != last) {
			iterator tmp(first);
			++first;
			erase(tmp);
		}
		return ;
	}

	template<MAP_TEMPLATE>
	void MAP_CLASS::swap(map &rhs) {
		swap(_tree, rhs._tree);
		swap(_size, rhs._size);
		swap(_comp, rhs._comp);
		return ;
	}

	template<MAP_TEMPLATE>
	void MAP_CLASS::clear(void) {
		erase(begin(), end());
		return ;
	}

	// -Other Methods
	template<MAP_TEMPLATE>
	typename MAP_CLASS::key_compare MAP_CLASS::key_comp(void) const {
		return (this->_comp);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::value_compare MAP_CLASS::value_comp(void) const {
		return (value_compare(_comp));
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::find(const key_type &k) {
		Node* tmp = _tree.searchNode(_tree._root, k);

		if (tmp)
			return (iterator(tmp, _tree._lastElem, _comp));
		return (end());
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_iterator MAP_CLASS::find(const key_type &k) const {
		Node* tmp = _tree.searchNode(_tree._root, k);

		if (tmp)
			return (const_iterator(tmp, _tree._lastElem, _comp));
		return (end());
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::size_type MAP_CLASS::count(const key_type &k) const {
		Node* tmp = _tree.searchNode(_tree._root, k);
		
		return (tmp ? true: false);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::lower_bound(const key_type &k) {
		iterator it = begin();

		for (; it != end(); ++it)
			if (!_comp(it->first, k))
				break;
		return (it);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_iterator MAP_CLASS::lower_bound(const key_type &k) const {
		const_iterator it = begin();

		for (; it != end(); ++it)
			if (!_comp(it->first, k))
				break;
		return (it);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::iterator MAP_CLASS::upper_bound(const key_type &k) {
		iterator it = begin();

		for (; it != end(); ++it)
			if (_comp(k, it->first))
				break;
		return (it);
	}

	template<MAP_TEMPLATE>
	typename MAP_CLASS::const_iterator MAP_CLASS::upper_bound(const key_type &k) const {
		const_iterator it = begin();

		for (; it != end(); ++it)
			if (_comp(k, it->first))
				break;
		return (it);
	}

	template<MAP_TEMPLATE>
	ft::pair<typename MAP_CLASS::iterator, typename MAP_CLASS::iterator>
	MAP_CLASS::equal_range(const key_type &k) {
		iterator it = upper_bound(k);

		if (it != begin()) {
			--it;
			if (_comp(it->first, k) || _comp(k, it->first))
				++it;
		}
		iterator next(it);
		if (it != end())
			++next;
		return (make_pair<iterator, iterator>(it, next));
	}

	template<MAP_TEMPLATE>
	ft::pair<typename MAP_CLASS::const_iterator, typename MAP_CLASS::const_iterator>
	MAP_CLASS::equal_range(const key_type &k) const {
		const_iterator it = upper_bound(k);

		if (it != begin()) {
			--it;
			if (_comp(it->first, k) || _comp(k, it->first))
				++it;
		}
		const_iterator next(it);
		if (it != end())
			++next;
		return (make_pair<const_iterator, const_iterator>(it, next));
	}

	// -Private Methods
	template<MAP_TEMPLATE>
	template <typename U>
	void MAP_CLASS::swap(U& a, U& b) {
		U tmp = a;
		a = b;
		b = tmp;
		return ;
	}

	// -Operator Functions
	template<MAP_TEMPLATE>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs.size() == rhs.size());
	}

	template<MAP_TEMPLATE>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs == rhs));
	}

	template<MAP_TEMPLATE>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<MAP_TEMPLATE>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template<MAP_TEMPLATE>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template<MAP_TEMPLATE>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template<MAP_TEMPLATE>
	void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs) {
		lhs.swap(rhs);
		return ;
	}
}

#endif
