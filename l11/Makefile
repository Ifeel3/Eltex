NAME	= l11
CC		= gcc
INCLUDES= includes/
CFLAGS	= -Wall -Werror -Wextra -std=c99 -I$(INCLUDES)
SRC		= src/list.c \
		src/main.c
OBJ		= $(SRC:src/%.c=obj/%.o)
DEBUG	= false

obj/%.o: src/%.c
ifdef release
	$(CC) $(CFLAGS) -c $? -o $@
else
	$(CC) $(CFLAGS) -g -c $? -o $@
endif

.PHONY: all re clean fclean

all: $(NAME)

release:
	@make release=1

obj:
	@mkdir obj

$(NAME): obj $(OBJ)
	$(CC) $(OBJ) -o $@

re: fclean all

fclean: clean
	@rm -rf obj

clean:
	@rm -f $(NAME)