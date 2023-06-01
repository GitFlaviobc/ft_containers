# ****************************************************************************************** #
#                                                                                            #
#                                                         :::::::::: :::::::::   :::::::     #
#  Makefile                                              :+:        :+:    :+: :+:    :+     #
#                                                       +:+        +:+    +:+ +:+            #
#  By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+              #
#                                                    +#+        +#+    +#+ +#+               #
#  Created: 2022/09/18 10:54:19 by Flavio BC        #+#        #+#    #+# #+#    #+#         #
#  Updated: 2022/12/10 15:26:26 by Flavio BC       ###        #########   ########           #
#  License: MIT                                                                              #
#                                                                                            #
# ****************************************************************************************** #


RES = results/
MAPFT = test_map_ft.mk
MAPSTD = test_map_std.mk
VECFT = test_vec_ft.mk
VECSTD = test_vec_std.mk
CONTAINERS = test_map_ft test_map_std test_vector_ft test_vector_std

all: $(CONTAINERS)

$(CONTAINERS) :
	make -f $(MAPFT)
	make -f $(MAPSTD)
	make -f $(VECFT)
	make -f $(VECSTD)

testvec:
	make test -f $(VECFT)
	make test -f $(VECSTD)
	@bash print_result.sh vector_ft vector_std Vector

testmap:
	make test -f $(MAPFT)
	make test -f $(MAPSTD)
	@bash print_result.sh map_ft map_std Map

cleanvec:
	make clean -f $(VECFT)
	make clean -f $(VECSTD)

cleanmap:
	make clean -f $(MAPFT)
	make clean -f $(MAPSTD)

clean: cleanvec cleanmap

fclean:
	make fclean -f $(MAPFT)
	make fclean -f $(MAPSTD)
	make fclean -f $(VECFT)
	make fclean -f $(VECSTD)
	rm -rf $(RES)

re:		fclean all

.PHONY: all clean fclean re test