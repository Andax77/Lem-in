NAME = lem-in
GREP = grep "Error"
INC_PATH = includes
SRC_PATH = src
SRC_NAME = lem_in.c\
			lem_in2.c\
			expand.c\
			ft_go.c\
			ft_start_end.c\
			# ft_algo.c

OBJ_PATH = obj
LDFLAGS = -L libft/ -lft
FLAGS = -I includes -I libft
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft
	@libtool -static -o $(NAME) $(OBJ) libft/libft.a
	@gcc $(FLAGS) $(LDFLAGS) $(CFLAGS) -o $@ $^
	@printf '\033[32m[ ✔ ] %s\n\033[0m' " 🍯 Create Lem_in🍯   [ ✔ ]"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(FLAGS) $(CFLAGS) -c $< -o $@
	@printf '\033[35m[ ✔ ] %s\n\033[0m' "$<"

clean:
	@make -C libft clean
	@$(RM) $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "🔥 Push_Swap Cleaned🔥  [ ✔ ]"

fclean: clean
	@make -C libft fclean
	@$(RM) $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "✨ Push_Swap Cleaned✨  [ ✔ ]"

re: fclean all

norme:
	@norminette src/*c >> norme
	@norminette $(INC_PATH) >> norme
	@grep -B 1 "Error" norme
	@rm norme
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "All is Normed"

.PHONY: all, clean, fclean, re, norme
