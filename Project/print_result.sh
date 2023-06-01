# ****************************************************************************************** #
#                                                                                            #
#                                                         :::::::::: :::::::::   :::::::     #
#  print_result.sh                                       :+:        :+:    :+: :+:    :+     #
#                                                       +:+        +:+    +:+ +:+            #
#  By: Flavio BC <github.com/GitFlaviobc>             :#::+::#   +#++:++#+  +#+              #
#                                                    +#+        +#+    +#+ +#+               #
#  Created: 2022/12/10 18:16:17 by Flavio BC        #+#        #+#    #+# #+#    #+#         #
#  Updated: 2022/12/10 18:16:31 by Flavio BC       ###        #########   ########           #
#  License: MIT                                                                              #
#                                                                                            #
# ****************************************************************************************** #

#!/bin/bash

clear
echo "============== FT VS STD, CPP differences ==============
"
grep -f tests/$1.cpp --fixed-strings --line-regexp --invert-match tests/$2.cpp
echo "
==================== End Differences ====================
"
echo "============== FT VS STD, output differences ==============
"
grep -f results/$1.txt --fixed-strings --line-regexp --invert-match results/$2.txt
echo "
==================== End Differences ====================
"
echo "============== Time Execution in miliseconds =============="
echo "	=========== $3: FT / STD ==========="
echo "		$(tail -n 1 results/$1.txt) / $(tail -n 1 results/$2.txt)"
echo "scale = 6;$(tail -n 1 results/$1.txt) / $(tail -n 1 results/$2.txt)" | bc | awk '{printf "\t\t\t%f\n", $$0}'
echo "
===================== End $3 Test ====================="
