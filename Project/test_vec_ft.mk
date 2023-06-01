# ****************************************************************************************** #
#                                                                                            #
#                                                         :::::::::: :::::::::   :::::::     #
#  test_vec_ft.mk                                        :+:        :+:    :+: :+:    :+     #
#                                                       +:+        +:+    +:+ +:+            #
#  By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+              #
#                                                    +#+        +#+    +#+ +#+               #
#  Created: 2022/12/08 15:02:42 by Flavio BC        #+#        #+#    #+# #+#    #+#         #
#  Updated: 2022/12/08 15:15:21 by Flavio BC       ###        #########   ########           #
#  License: MIT                                                                              #
#                                                                                            #
# ****************************************************************************************** #

NAME		= test_vector_ft

INCLUDE		:= includes/
ITERATOR	:= $(INCLUDE)iterators
MAP			:= $(INCLUDE)map
BSTREE		:= $(INCLUDE)avltree
UTILS		:= $(INCLUDE)utilities
VEC			:= $(INCLUDE)vector
INCLUDES	:= $(ITERATOR) $(MAP) $(BSTREE) $(UTILS) $(VEC)

SRC_DIR		:= tests/
OBJ_DIR		:= obj/

SRCS		:= $(SRC_DIR)vector_ft.cpp
OBJS		:= $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
IFLAGS		:= $(addprefix -I, $(INCLUDES))

CXX			:= c++
RM			:= rm -rf
CXXFLAGS	+= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g $(IFLAGS)

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ_DIR)
	$(RM) results/vector_ft.txt

fclean:	clean
	$(RM) $(NAME)

test: $(NAME)
	mkdir -p results
	./$(NAME) > results/vector_ft.txt

re:		fclean $(NAME)

.PHONY:		all clean fclean re test