# ****************************************************************************************** #
#                                                                                            #
#                                                         :::::::::: :::::::::   :::::::     #
#  test_vec_std.mk                                       :+:        :+:    :+: :+:    :+     #
#                                                       +:+        +:+    +:+ +:+            #
#  By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+              #
#                                                    +#+        +#+    +#+ +#+               #
#  Created: 2022/12/08 15:02:45 by Flavio BC        #+#        #+#    #+# #+#    #+#         #
#  Updated: 2022/12/08 15:15:55 by Flavio BC       ###        #########   ########           #
#  License: MIT                                                                              #
#                                                                                            #
# ****************************************************************************************** #

NAME		= test_vector_std

SRC_DIR		:= tests/
OBJ_DIR		:= obj/

SRCS		:= $(SRC_DIR)vector_std.cpp
OBJS		:= $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

CXX			:= c++
RM			:= rm -rf
CXXFLAGS	+= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ_DIR)
	$(RM) results/vector_std.txt

fclean:	clean
	$(RM) $(NAME)

test: $(NAME)
	mkdir -p results
	./$(NAME) > results/vector_std.txt

re:		fclean $(NAME)

.PHONY:		all clean fclean re test