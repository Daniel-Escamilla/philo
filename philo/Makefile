NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3# -Wpedantic -Wconversion -Wshadow -Wstrict-overflow=5 -Wstrict-aliasing=3 -Wcast-qual -Wwrite-strings -Wundef -Wpointer-arith -Wfloat-equal -Wformat=2 -Wredundant-decls -Wmissing-prototypes -Wmissing-declarations -Wno-sign-conversion

SRC =	src/main/ft_main.c \
		src/utils/ft_itoa.c \
		src/utils/ft_utils.c \
		src/utils/ft_calloc.c \
		src/utils/ft_atoi_mod.c \
		src/utils/ft_print_philo.c \

OBJ_DIR = $(NAME)_objects

OBJ = $(SRC:.c=.o)

SRC_OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
