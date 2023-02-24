# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:43:40 by svalente          #+#    #+#              #
#    Updated: 2023/02/24 17:37:13 by svalente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = create_list ft_atol op_push op_rev_rotate op_rotate op_swap\
push_swap rules_checker sort_3 sort_5 find\
sort_all_numbers sort_long lists_functions \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

$(VERBOSE).SILENT:

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

all: $(NAME)

$(NAME): $(SRC:=.o)
		make -C $(FT_PRINTF_PATH)
		$(CC) $(CFLAGS) $(SRC:=.o) $(FT_PRINTF) -o $(NAME) 

clean:
		$(RM) $(SRC:=.o)
		make clean -C $(FT_PRINTF_PATH)

fclean: clean
		make fclean -C $(FT_PRINTF_PATH)
		$(RM) $(NAME)
	
re: fclean all

#-fsanitize=address