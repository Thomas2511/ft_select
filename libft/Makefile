# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:00:53 by tdieumeg          #+#    #+#              #
#    Updated: 2016/03/25 18:20:00 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binaries
CC		= /usr/bin/clang
RM		= /bin/rm
MAKE	= /usr/bin/make
MKDIR	= /bin/mkdir
AR		= /usr/bin/ar
RANLIB	= /usr/bin/ranlib

# app name
NAME	= libft.a

# dir
ROOT	= $(shell pwd)
OBJDIR	= $(ROOT)/objs
SRCDIR	= $(ROOT)/srcs
INCDIR	= $(ROOT)/includes

# compil flags
CFLAGS	= -I $(INCDIR) -Wall -Wextra -Werror

# source files
SRC		= ft_atoi.c \
		  ft_atoi_base.c \
		  ft_bzero.c \
		  ft_clear_tab.c \
		  ft_clstdelone.c \
		  ft_clstnew.c \
		  ft_clstpush.c \
		  ft_concat.c \
		  ft_count_tab.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_dlstnew.c \
		  ft_dlstpushfront.c \
		  ft_dlist_clear.c \
		  ft_list_clear.c \
		  ft_lstadd.c \
		  ft_lstaddend.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstpushback.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putnbr_endl.c \
		  ft_putnbr_endl_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_split_to_list.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_nmatch.c \
		  ft_toupper.c

# obj
OBJS	= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling libft..."
	@$(AR) -rc $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $< -o $@ -c $(CFLAGS)

$(OBJDIR):
	@$(MKDIR) $@

clean:
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
