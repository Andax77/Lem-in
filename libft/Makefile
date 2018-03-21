#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anhuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 11:04:15 by anhuang           #+#    #+#              #
#    Updated: 2018/01/15 17:41:34 by anhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_atoi.c \
	  ./ft_bzero.c \
	  ./ft_isalnum.c \
	  ./ft_isalpha.c \
	  ./ft_isascii.c \
	  ./ft_isdigit.c \
	  ./ft_isprint.c \
	  ./ft_itoa.c \
	  ./ft_memalloc.c \
	  ./ft_memccpy.c \
	  ./ft_memchr.c \
	  ./ft_memcmp.c \
	  ./ft_memcpy.c \
	  ./ft_memdel.c \
	  ./ft_memmove.c \
	  ./ft_memset.c \
	  ./ft_putchar.c \
	  ./ft_putchar_fd.c \
	  ./ft_putendl.c \
	  ./ft_putendl_fd.c \
	  ./ft_putnbr.c \
	  ./ft_putnbr_fd.c \
	  ./ft_putstr.c \
	  ./ft_putstr_fd.c \
	  ./ft_strcat.c \
	  ./ft_strchr.c \
	  ./ft_strclr.c \
	  ./ft_strcmp.c \
	  ./ft_strcpy.c \
	  ./ft_strdel.c \
	  ./ft_strdup.c \
	  ./ft_strequ.c \
	  ./ft_striter.c \
	  ./ft_striteri.c \
	  ./ft_strjoin.c \
	  ./ft_strlcat.c \
	  ./ft_strlen.c \
	  ./ft_strmap.c \
	  ./ft_strmapi.c \
	  ./ft_strncat.c \
	  ./ft_strncmp.c \
	  ./ft_strncpy.c \
	  ./ft_strnequ.c \
	  ./ft_strnew.c \
	  ./ft_strnstr.c \
	  ./ft_strrchr.c \
	  ./ft_strsplit.c \
	  ./ft_strstr.c \
	  ./ft_strsub.c \
	  ./ft_strtrim.c \
	  ./ft_tolower.c \
	  ./ft_toupper.c \
	  ./ft_lstadd.c \
	  ./ft_lstdel.c \
	  ./ft_lstdelone.c \
	  ./ft_lstiter.c \
	  ./ft_lstmap.c \
	  ./ft_lstnew.c \
	  ./count_let.c \
	  ./ft_count_words.c \
	  ./ft_swap.c \
	  ./get_next_line.c \
	  ./pf_big_char.c \
	  ./pf_big_hex.c \
	  ./pf_big_hex2.c \
	  ./pf_big_octal.c \
	  ./pf_big_octal2.c \
	  ./pf_big_string.c \
	  ./pf_big_string2.c \
	  ./pf_binary.c \
	  ./pf_char.c \
	  ./pf_charsets.c \
	  ./pf_double.c \
	  ./pf_hex.c \
	  ./pf_hex2.c \
	  ./pf_int.c \
	  ./pf_octal.c \
	  ./pf_octal2.c \
	  ./pf_percent.c \
	  ./pf_pointer.c \
	  ./pf_putchar.c \
	  ./pf_putchar2.c \
	  ./pf_putchard.c \
	  ./pf_putlong.c \
	  ./pf_putshort.c \
	  ./pf_size_secure.c \
	  ./pf_string.c \
	  ./pf_uint.c \

OBJ = $(SRC:.c=.o)
DEL = rm -f
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@printf '\033[32m      [=================] %s\n\033[0m'
	@printf '\033[32m      |🐳    Success ! 🐳 | %s\n\033[0m'
	@printf '\033[32m      |🐳    libft.a   🐳 | %s\n\033[0m'
	@printf '\033[32m      |🐳  was summoned🐳 | %s\n\033[0m'
	@printf '\033[32m      [=================] %s\n\033[0m'
	@printf '\033[32m[ ✔ ] %s\n\033[0m' " 🍿 Create Printf🍿    [ ✔ ]"


%.o: %.c
	@gcc $(FLAG) -c $^
	@printf '\033[35m[ 🍟  ] %s\n\033[0m' "$<"

clean:
	@$(DEL) $(OBJ)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "   🔥 Libft Clean🔥     [ ✔ ]"

fclean: clean
	@$(DEL) $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "   ✨ Libft Fclean✨    [ ✔ ]"

re: fclean all
