/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* vector.tpp                                            :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/11/07 15:12:02 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/08 17:06:21 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "vector.hpp"

namespace ft {
	// -Constructors
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc) {
		this->_alloc = alloc; 
		this->_data = NULL;
		this->_size = 0;
		this->_capacity = 0;
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) {
		this->_alloc = alloc;
		this->_data = NULL;
		this->_size = 0;
		this->_capacity = 0;
		if (n > max_size()) {
			throw std::length_error("length_error");
		}
		this->_data = _alloc.allocate(n);
		if (this->_data == NULL) {
			throw std::bad_alloc();
		}
		for (size_t i = 0; i < n; i++) {
			this->_alloc.construct(_data + i, val);
			this->_size++;
		}
		this->_capacity = n;
		return ;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(vector const &rhs) {
		this->_alloc = rhs._alloc;
		this->_data = NULL;
		this->_size = 0;
		this->_capacity = 0;
		*this = rhs;
		return ;
	}

	// -Destructor
	template <class T, class Alloc>
	vector<T, Alloc>::~vector(void) {
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.destroy(_data + i);
		}
		if (this->_capacity > 0) {
			this->_alloc.deallocate(_data, _size);
		}
		this->_size = 0;
		this->_capacity = 0;
		return ;
	}

	// -Operators
	template <class T, class Alloc>
	vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &rhs) {
		if (this != &rhs) {
			_alloc.deallocate(this->_data, this->_capacity);
			this->_data = _alloc.allocate(rhs._capacity);
			for (size_type i = 0; i < rhs._size; i++)
				this->_data[i] = rhs._data[i];
			this->_size = rhs._size;
		}
		return (*this);
	}
	
	// -Capacity Methods
	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::size(void) const {
		return (this->_size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size(void) const {
		return (this->_alloc.max_size());
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::resize(size_type n) {
		while (n < this->_size) {
			this->pop_back();
		}
		if (n > this->_capacity) {
			this->reserve(n);
		}
		while (n > _size) {
			this->push_back(T());
		}
		return ;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::resize(size_type n, T val) {
		while (n < this->_size) {
			this->pop_back();
		}
		if (n > this->_capacity) {
			this->reserve(n);
		}
		while (n > _size) {
			this->push_back(val);
		}
		return ;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity(void) const {
		return (this->_capacity);
	}

	template <class T, class Alloc>
	bool vector<T, Alloc>::empty(void) const {
		return (this->_size == 0 ? true : false);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::reserve(size_type new_cap) {
		if (new_cap > this->_capacity) {
			if (new_cap > this->max_size()) {
				throw std::length_error("length_error");
			}
			pointer tmp = this->_alloc.allocate(new_cap);
			if (tmp == NULL) {
				throw std::bad_alloc();
			}
			for (size_t i = 0; i < this->_size; i++) {
				this->_alloc.construct(tmp + i, this->_data[i]);
				this->_alloc.destroy(_data + i);
			}
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = tmp;
			this->_capacity = new_cap;
		}
		return ;
	}

	// -Element Access Methods
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const {
		return (this->_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n) {
		return (this->_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
		if (n >= this->_size) {
			throw std::out_of_range("out_of_range");
		}
		return (this->_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
		if (n >= this->_size) {
			throw std::out_of_range("out_of_range");
		}
		return (this->_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front(void) const {
		return (this->_data[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::front(void) {
		return (this->_data[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back(void) const {
		return (this->_data[this->_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::back(void) {
		return (this->_data[this->_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::value_type *vector<T, Alloc>::data(void) {
		return (this->_data);
	}

	template <class T, class Alloc>
	const typename vector<T, Alloc>::value_type *vector<T, Alloc>::data(void) const {
		return (this->_data);
	}

	// -Modifiers Methods
	template <class T, class Alloc>
	template <class InputIterator>
	void vector<T, Alloc>::assign(InputIterator first, InputIterator last) {
		this->clear();
		this->insert(this->begin(), first, last);
		return ;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::assign(size_t count, const T &value) {
		this->clear();
		for(size_t i = 0; i < count; i++)
			this->pop_back(value);
		return ;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::push_back(T const &x) {
		if (this->_size == this->_capacity) {
			if (this->_capacity == 0)
				this->_capacity++;
			this->reserve(this->_capacity * 2);
		}
		this->_data[this->_size] = x;
		this->_size++;
		return ;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::pop_back(void) {
		if (this->_size > 1) {
			this->_alloc.destroy(&this->_data[this->_size - 1]);
			this->_size--;
		}
		return ;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, T const &value) {
		int	index;

		index = pos - (this->begin());
		if ((this->_size + 1) > this->_capacity) {
			this->reserve(this->_capacity * 2);
			pos = this->begin() + index;
		}
		this->_size++;
		for (int aux = this->_size; aux > index; aux--)
			this->_data[aux] = this->_data[aux - 1];
		this->_data[index] = value;
		return (pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, size_t count, T const &value) {
		int	index;
		int	resized;

		index = pos - (this->begin());
		resized = this->_capacity;
		if ((this->_size + count) > this->_capacity) {
			while (resized < (this->_size + count))
				resized *= 2;
			this->reserve(resized);
			pos = this->begin() + index;
		}
		this->_size += count;
		for (int aux = this->_size; aux >= (index + count); aux--)
			this->_data[aux] = this->_data[aux - count];
		for (int i = 0; i < count; i++)
			this->_data[index + i] = value;
		return (pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, iterator begin, iterator end) {
		unsigned int	index;
		unsigned int	resized;
		int	count;

		if (begin > end)
			throw std::exception();
		index = pos - (this->begin());
		resized = this->_capacity;
		count = end - begin;
		if ((this->_size + count) > this->_capacity) {
			while (resized < (this->_size + count))
				resized++;
			this->reserve(resized);
			pos = this->begin() + index;
		}
		this->_size += count;
		for (unsigned int aux = this->_size; aux >= (index + count); aux--)
			this->_data[aux] = this->_data[aux - count];
		for (int i = 0; i < count; i++)
			this->_data[index + i] = *(begin + i);
		return (pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {
		iterator	aux;

		aux = this->begin();
		for (unsigned int index = pos - aux; index < (this->_size - 1); index++)
			this->_data[index] = this->_data[index + 1];
		this->_size--;
		return (pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator begin, iterator end) {
		iterator	aux;
		int			diff;

		if (begin > end)
			throw std::exception();
		diff = end - begin;
		aux = this->begin();
		for (unsigned int index = begin - aux; index < this->_size; index++) {
			this->_data[index] = this->_data[index + diff];
		}
		this->_size -= end - begin;
		return (begin);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::swap(vector &vec) {
		T*				auxContent;
		unsigned int	auxSize;
		unsigned int	auxCapacity;

		auxContent = vec._data;
		auxSize = vec.size();
		auxCapacity = vec.capacity();
		vec._data = this->_data;
		vec._size = this->_size;
		vec._capacity = this->_capacity;
		this->_data = auxContent;
		this->_size = auxSize;
		this->_capacity = auxCapacity;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::clear(void) {
		this->resize(1);
		this->_size = 0;
		return ;
	}

	// -Iterators Methods
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::begin(void) {
		return (iterator(this->_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::end(void) {
		return (iterator(this->_data + this->_size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cbegin(void) const {
		return (const_iterator(this->_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::cend(void) const {
		return (const_iterator(this->_data + this->_size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void) {
		reverse_iterator	it(this->_data + (this->_size - 1));

		return (it);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void) {
		reverse_iterator	it(this->_data);
		it++;

		return (it);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crbegin(void) const {
		const_reverse_iterator const	it(this->_data + (this->_size - 1));

		return (it);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::crend(void) const {
		const_reverse_iterator const	it(this->_data);
		it++;

		return (it);
	}

	// -Getter
	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator(void) const {
		return (allocator_type());
	}

	// -Functions
	template <class T, class Alloc>
	inline bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin()) && lhs.size() == rhs.size());
	}

	template <class T, class Alloc>
	inline bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	inline bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
	}

	template <class T, class Alloc>
	inline bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	inline bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (ft::lexicographical_compare(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend()));
	}

	template <class T, class Alloc>
	inline bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template<class T, class Alloc>
	inline void	swap(vector<T, Alloc> lhs, vector<T, Alloc> rhs) {
		lhs.swap(rhs);
	}
}

#endif
