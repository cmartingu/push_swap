NAME = push_swap

FILES = push_swap.c movements1.c errors.c try.c three_case.c list_functions.c movements2.c aux_functions.c
OBJECTS = $(FILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
