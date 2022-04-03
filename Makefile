# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 09:51:48 by pleoma            #+#    #+#              #
#    Updated: 2022/04/03 10:53:00 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
FLAGS_O	=	-O2

OBJDIR	=	obj
SRCDIR	=	src
HEADER	=	includes/minishell.h

OBJ		=	$(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
SRC 	= 	$(addprefix $(SRCDIR)/, $(SOURCES))
SOURCES	=	main.c\
			minishell.c\
		
all		: $(NAME)

$(NAME)	: $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "compiled $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) Makefile
	${CC} ${FLAGS} ${FLAGS_O} -c $< -o $@ 

$(OBJDIR):
		@mkdir $@

$(OBJ): | $(OBJDIR)

clean :
	@rm -rf $(OBJDIR)
	@echo "Removing obj"

fclean : clean
	@rm -f $(NAME)
	@echo "Removing all"

re : fclean all

.PHONY : all clean fclean re