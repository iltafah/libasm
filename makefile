# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iltafah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 16:56:28 by iltafah           #+#    #+#              #
#    Updated: 2020/12/12 13:28:29 by iltafah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAGS = -Wall -Wextra -Werror

SRC = Mandatory_file/ft_read.s Mandatory_file/ft_strcmp.s  Mandatory_file/ft_strcpy.s  Mandatory_file/ft_strdup.s  Mandatory_file/ft_strlen.s  Mandatory_file/ft_write.s

B_SRC = _bonus/ft_atoi_base_bonus.s  _bonus/ft_list_push_front_bonus.s  _bonus/ft_list_remove_if_bonus.s   _bonus/ft_list_sort_bonus.s  _bonus/ft_list_size_bonus.s 

OBJ = $(SRC:.s=.o)

B_OBJ = $(B_SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

bonus : all $(B_OBJ)
	ar rc $(NAME) $(B_OBJ)
	ranlib $(NAME)

%.o : %.s
	nasm -f macho64 $^

clean :
		rm -f $(OBJ) $(B_OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
