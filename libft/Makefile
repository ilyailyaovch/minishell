# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:34:59 by pleoma            #+#    #+#              #
#    Updated: 2022/05/02 11:08:48 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror

SRC 	=   ft_isalpha.c		ft_toupper.c		ft_substr.c\
			ft_isdigit.c		ft_tolower.c		ft_strjoin.c\
			ft_isalnum.c		ft_strchr.c			ft_strtrim.c\
			ft_isascii.c		ft_strrchr.c		ft_split.c\
			ft_isprint.c		ft_strncmp.c		ft_itoa.c\
			ft_utoa.c			ft_htoa.c\
			ft_strlen.c			ft_memchr.c			ft_strmapi.c\
			ft_memset.c			ft_memcmp.c			ft_striteri.c\
			ft_bzero.c			ft_strnstr.c		ft_putchar_fd.c\
			ft_memcpy.c			ft_atoi.c			ft_putstr_fd.c\
			ft_memmove.c							ft_putendl_fd.c\
			ft_strlcpy.c		ft_calloc.c			ft_putnbr_fd.c\
			ft_strlcat.c		ft_strdup.c\
			ft_lstnew_bonus.c						ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c					ft_lstsize_bonus.c\
			ft_lstclear_bonus.c						ft_lstiter_bonus.c\
			ft_lstdelone_bonus.c					ft_lstlast_bonus.c\
			ft_lstmap_bonus.c						ft_lstlen_bonus.c\
			get_next_line.c\

OBJ 	= $(patsubst %.c,%.o,$(SRC))
HEADER 	= libft.h

%.o		:	%.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

all		: 	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	@ar rcs $(NAME) *.o

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm  -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re