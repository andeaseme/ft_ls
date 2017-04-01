# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 17:12:26 by aphan             #+#    #+#              #
#    Updated: 2017/03/21 17:40:13 by aphan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LDIR =	libft
IDIR =	includes
ODIR :=	obj
SDIR =	src

HEADERS = -I $(IDIR) -I $(LDIR)/$(IDIR)
CC = gcc
CFLAGS = $(HEADERS) -Wall -Wextra -Werror

LIBFT =	$(LDIR)/libft.a
DEPS =	$(IDIR)/ft_ls.h

_OBJ =	ls_main.o ls_compare.o ls_bool.o
OBJ :=	$(addprefix $(ODIR)/,$(_OBJ))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ): | $(ODIR)

$(ODIR):
		mkdir -p $@
		@echo 'make directory obj'

$(LIBFT):
		$(MAKE) -C $(LDIR)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) -o $@ $^ $(CFLAGS)
		@echo 'compile ft_ls'

clean:
		/bin/rm -rfv $(ODIR)
		@echo 'clean ft_ls objects'
		$(MAKE) -C $(LDIR) $@

fclean: clean
		/bin/rm -f $(NAME)
		@echo 'clean ft_ls'
		$(MAKE) -C $(LDIR) $@

re: fclean all

.PHONY: all clean fclean re test
