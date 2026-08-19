ARCHIVE = ft_btree.a
FLAGS =	-Wall -Wextra -Werror -g

SOURCES_DIR = src
SOURCES = $(wildcard $(SOURCES_DIR)/*.c)

OBJECTS_DIR = obj
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))


all: $(ARCHIVE)

$(ARCHIVE): $(OBJECTS)
	$(info archiving $(ARCHIVE))
	@ar rcs $@ $^

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	@mkdir -p $(OBJECTS_DIR)
	$(info compiling $< into $@)
	@gcc $(FLAGS) -I. -c $< -o $@

clean:
	$(info deleting $(OBJECTS_DIR))
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	$(info deleting $(ARCHIVE))
	@rm -f $(ARCHIVE)

re: fclean all

.PHONY: all clean fclean re