SRCS = \
	genetic_algorithm.c

OBJS = $(SRCS:%.c=%.o)
INCS = ./
NAME = mylib.a
AR = ar rcs
CC= gcc
FLAGS = -Wall -Wextra -Werror
RM = rm

.c.o:
	$(CC) $(FLAGS) -c $< -o $@  -I $(INCS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re