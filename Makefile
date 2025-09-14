ARC		=	ft_btree.a
HDR		=	ft_btree.h
SRC_DIR =	src
OBJ_DIR =	obj
SRC		=	$(wildcard $(SRC_DIR)/*.c)
OBJ		=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

FLAGS	=	-Wall -Wextra -Werror -g

all: $(ARC)

$(ARC): $(OBJ)
	ar rcs $(ARC) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(ARC)

re: fclean all

.PHONY: all clean fclean re