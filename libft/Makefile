# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 13:26:36 by aphan             #+#    #+#              #
#    Updated: 2017/02/25 20:59:06 by aphan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

IDIR = includes/
CC = gcc
CFLAGS = -I $(IDIR) -Wall -Wextra -Werror

ODIR := obj
SDIR = src
PRINTF_SDIR =	$(SDIR)/ft_printf
GRAPH_SDIR =	$(SDIR)/graph
UTILITY_SDIR =	$(SDIR)/utility
SORT_SDIR =		$(SDIR)/sort
VPATH = $(SDIR) $(GRAPH_SDIR) $(UTILITY_SDIR) $(SORT_SDIR)

_DEPS = libft.h get_next_line.h ft_printf.h
DEPS = $(addprefix $(IDIR)/,$(_DEPS))

_OBJ =	ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
		ft_isdigit.o ft_isprint.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		ft_memcpy.o ft_memmove.o ft_memset.o ft_strcat.o ft_strchr.o \
		ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlcat.o ft_strlen.o \
		ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnstr.o ft_strrchr.o \
		ft_strstr.o ft_tolower.o ft_toupper.o ft_memalloc.o ft_memdel.o \
		ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
		ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
		ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_putchar.o ft_putstr.o \
		ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o ft_lstnew.o ft_lstdelone.o \
		ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
		ft_itoa_base.o ft_atoi_base.o ft_strndup.o ft_split_whitespaces.o \
		ft_islower.o ft_isupper.o ft_isnumber.o ft_isblank.o \
		ft_strtrimc.o ft_strlcpy.o ft_atol.o ft_strrealloc.o ft_power.o \
		get_next_line.o ft_intswap.o ft_lstdup.o ft_lstclr.o ft_findint.o \
		ft_isintstr.o ft_isnbrstr.o ft_realloc.o ft_lstadd_after.o \
		ft_lstfree.o ft_strcat_multi.o ft_memdup.o ft_lstiter2.o

_PRINTF_OBJ =	ft_printf.o pf_parse.o pf_ismodifier.o pf_s.o pf_d.o pf_u.o \
				pf_p.o pf_o.o pf_x.o pf_c.o pf_b.o

_GRAPH_OBJ =	graph_add_edge.o graph_destroy.o search_dfs_bfs.o \
				graph_count.o graph_foreach.o search_info_create.o \
				graph_create.o graph_has_edge.o search_info_destroy.o

_UTILITY_OBJ = 	ft_option128.o

_SORT_OBJ =		ft_quicksort_int.o ft_quicksort.o ft_mergesort_int.o \
				ft_mergesort.o

OBJ :=	$(addprefix $(ODIR)/,$(_OBJ)) \
		$(addprefix $(ODIR)/,$(_PRINTF_OBJ)) \
		$(addprefix $(ODIR)/,$(_GRAPH_OBJ)) \
		$(addprefix $(ODIR)/,$(_UTILITY_OBJ)) \
		$(addprefix $(ODIR)/,$(_SORT_OBJ))

all: $(NAME)

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
$(ODIR)/%.o: $(PRINTF_SDIR)/%.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS) -Wno-varargs

$(OBJ): | $(ODIR)

$(ODIR):
		mkdir -p $@
		@echo 'make directory obj'

$(NAME): $(OBJ)
		ar rc $@ $^
		ranlib $@
		@echo 'compile libft.a'

clean:
		/bin/rm -rfv $(ODIR)
		@echo 'clean libft objects'

fclean: clean
		/bin/rm -f $(NAME) 
		@echo 'clean libft.a'

re: fclean all

.PHONY: all clean fclean re
