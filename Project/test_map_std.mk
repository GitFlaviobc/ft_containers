# ****************************************************************************************** #
#                                                                                            #
#                                                         :::::::::: :::::::::   :::::::     #
#  test_map_std.mk                                       :+:        :+:    :+: :+:    :+     #
#                                                       +:+        +:+    +:+ +:+            #
#  By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+              #
#                                                    +#+        +#+    +#+ +#+               #
#  Created: 2022/12/08 15:02:39 by Flavio BC        #+#        #+#    #+# #+#    #+#         #
#  Updated: 2022/12/08 15:15:08 by Flavio BC       ###        #########   ########           #
#  License: MIT                                                                              #
#                                                                                            #
# ****************************************************************************************** #

NAME		= test_map_std

SRC_DIR		:= tests/
OBJ_DIR		:= obj/

SRCS		:= $(SRC_DIR)map_std.cpp
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
	$(RM) results/map_std.txt

fclean:	clean
	$(RM) $(NAME)

test: $(NAME)
	mkdir -p results
	./$(NAME) > results/map_std.txt

re:		fclean $(NAME)

.PHONY:		all clean fclean re test