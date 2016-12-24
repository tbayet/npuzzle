# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbayet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 10:53:13 by tbayet            #+#    #+#              #
#    Updated: 2016/04/04 18:53:33 by tbayet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

HEAD =	libft.h get_next_line.h

SRCS =	ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c 	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c 	\
		ft_isalnum.c 	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstadd.c		\
		ft_lstdel.c		\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lstnew.c		\
		ft_lstlen.c		\
		ft_strrealloc.c	\
		ft_strsort.c	\
		ft_strreplace.c	\
		ft_strreverse.c	\
		ft_strshift.c	\
		ft_puttab.c		\
		ft_sqrn.c		\
		ft_charstr.c	\
		ft_delstrtab.c	\
		ft_tablen.c		\
		ft_sorttab.c	\
		ft_revtab.c		\
		ft_itoabasep.c	\
		ft_intnew.c		\
		ft_putstrn.c	\
		ft_putstrcat.c	\
		ft_tabdup.c		\
		ft_deltab.c		\
		get_next_line.c	\
		ft_strcut.c		\
		ft_lstdelthis.c	\
		ft_voidstr.c	\
		ft_putcolor_fd.c\
		ft_strndup.c	\
		ft_strsplitone.c \
		ft_nbwords.c	\
		ft_tabzero.c	\
		ft_tabnew.c	\
		ft_absolute.c

OBJS =	$(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS);

fclean:	clean
	$(RM) $(NAME)
	
re:	fclean all

.PHONY : all clean fclean re
