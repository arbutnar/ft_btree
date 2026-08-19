ARCHIVE = ft_btree.a
FLAGS =	-Wall -Wextra -Werror -g

SOURCES_DIR = src
SOURCES = $(wildcard $(SOURCES_DIR)/*.c)

OBJECTS_DIR = obj
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))


all: $(ARCHIVE)

$(ARCHIVE): $(OBJECTS)
	ar rcs $@ $^

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	@mkdir -p $(OBJECTS_DIR)
	gcc $(FLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(ARCHIVE)

re: fclean all

.PHONY: all clean fclean re