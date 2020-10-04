# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warchiba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#              #
#    Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap
INCLUDE = libft/includes/
LIBPATH = libft/
FUNCCHECKER = operations.c main_checker.c arr_tools.c arr_tools_2.c create_arr.c
FUNCPUSHSWAP = main_push_swap.c quicksort.c operations.c arr_tools.c arr_tools_2.c create_arr.c push_swap.c
OBJCHECKER = $(FUNCCHECKER:.c=.o)
OBJPUSHSWAP = $(FUNCPUSHSWAP:.c=.o)


all: $(CHECKER) $(PUSHSWAP)

$(CHECKER): librun
	gcc -Wall -Wextra -Werror $(FUNCCHECKER) -I $(INCLUDE) -L $(LIBPATH) -lft -o $(CHECKER)

$(PUSHSWAP): librun
	gcc -Wall -Wextra -Werror $(FUNCPUSHSWAP) -I $(INCLUDE) -L $(LIBPATH) -lft -o $(PUSHSWAP)

librun:
	cd $(LIBPATH) && $(MAKE) all

clean:
	/bin/rm -Rf $(OBJCHECKER) $(OBJPUSHSWAP)
	cd $(LIBPATH) && $(MAKE) clean

fclean: clean
	/bin/rm -Rf $(CHECKER) $(PUSHSWAP)
	cd $(LIBPATH) && $(MAKE) fclean

re: fclean all
