# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstuder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 15:41:08 by adstuder          #+#    #+#              #
#    Updated: 2019/04/02 18:38:48 by adstuder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

S_PATH = ./
O_PATH = ./

SRC1 += $(S_PATH)main_checker.c
SRC1 += $(S_PATH)center.c
SRC1 += $(S_PATH)check_sort.c
SRC1 += $(S_PATH)checker.c
SRC1 += $(S_PATH)ft_atoi.c
SRC1 += $(S_PATH)ft_strcmp.c
SRC1 += $(S_PATH)ft_strdup.c
SRC1 += $(S_PATH)ft_strlen.c
SRC1 += $(S_PATH)ft_strsplit.c
SRC1 += $(S_PATH)get_med.c
SRC1 += $(S_PATH)get_min_max.c
SRC1 += $(S_PATH)get_next_line.c
SRC1 += $(S_PATH)init_piles.c
SRC1 += $(S_PATH)parsing.c
SRC1 += $(S_PATH)parsing_aux.c
SRC1 += $(S_PATH)push.c
SRC1 += $(S_PATH)swap.c
SRC1 += $(S_PATH)rotate.c
SRC1 += $(S_PATH)reverse_rotate.c
SRC1 += $(S_PATH)push_swap.c
SRC1 += $(S_PATH)push_swap_aux.c
SRC1 += $(S_PATH)quicksort.c
SRC1 += $(S_PATH)quicksort2.c
SRC1 += $(S_PATH)simple_sort.c
SRC1 += $(S_PATH)split.c
SRC1 += $(S_PATH)ab_get_min_max.c
SRC1 += $(S_PATH)free_piles_tab.c

SRC2 += $(S_PATH)main_push_swap.c
SRC2 += $(S_PATH)center.c
SRC2 += $(S_PATH)check_sort.c
SRC2 += $(S_PATH)checker.c
SRC2 += $(S_PATH)ft_atoi.c
SRC2 += $(S_PATH)ft_strcmp.c
SRC2 += $(S_PATH)ft_strdup.c
SRC2 += $(S_PATH)ft_strlen.c
SRC2 += $(S_PATH)ft_strsplit.c
SRC2 += $(S_PATH)get_med.c
SRC2 += $(S_PATH)get_min_max.c
SRC2 += $(S_PATH)get_next_line.c
SRC2 += $(S_PATH)init_piles.c
SRC2 += $(S_PATH)parsing.c
SRC2 += $(S_PATH)parsing_aux.c
SRC2 += $(S_PATH)push.c
SRC2 += $(S_PATH)swap.c
SRC2 += $(S_PATH)rotate.c
SRC2 += $(S_PATH)reverse_rotate.c
SRC2 += $(S_PATH)push_swap.c
SRC2 += $(S_PATH)push_swap_aux.c
SRC2 += $(S_PATH)quicksort.c
SRC2 += $(S_PATH)quicksort2.c
SRC2 += $(S_PATH)simple_sort.c
SRC2 += $(S_PATH)split.c
SRC2 += $(S_PATH)ab_get_min_max.c
SRC2 += $(S_PATH)free_piles_tab.c

GCC = gcc -c -Wall -Wextra -Werror

OBJ1 = $(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRC1))
OBJ2 = $(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRC2))

HEADER = push_swap.h

.PHONY: all clean fclean

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) 
$(NAME2): $(OBJ2) 

$(OBJ1) : $(O_PATH)%.o: $(S_PATH)%.c $(HEADER)
	$(GCC) $< -o $@	

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
