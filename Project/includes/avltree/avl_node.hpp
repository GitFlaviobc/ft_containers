/* **************************************************************************************** */
/*                                                                                          */
/*                                                        :::::::::: :::::::::   :::::::    */
/* avl_node.hpp                                          :+:        :+:    :+: :+:    :+    */
/*                                                      +:+        +:+    +:+ +:+           */
/* By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+             */
/*                                                   +#+        +#+    +#+ +#+              */
/* Created: 2022/12/07 10:31:02 by Flavio BC        #+#        #+#    #+# #+#    #+#        */
/* Updated: 2022/12/07 10:32:50 by Flavio BC       ###        #########   ########          */
/* License: MIT                                                                             */
/*                                                                                          */
/* **************************************************************************************** */

#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP

#include "pair.hpp"

namespace ft {
	template <typename Key, typename T>
	struct Node {
		ft::pair<const Key, T>	content;
		Node*					parent;
		Node*					left;
		Node*					right;
	};
}

#endif
