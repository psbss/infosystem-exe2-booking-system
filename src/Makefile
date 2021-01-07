SRCS = \
	lib.c \
	lib_sort.c \
	inquiry.c \
	dev.c \
	johnson_algorithm.c \

OBJS = $(SRCS:%.c=%.o)
INCS = mylib.h
MAIN = main.c
LIB_NAME = MYLIB
EXE_NAME = ExeBooking
CC = gcc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
RM = rm

.c.o:
	$(CC) $(FLAGS) -c $< -o $@ -I ${INCS}

$(LIB_NAME): $(OBJS)
	$(AR) $(LIB_NAME) $(OBJS)
	${CC} ${MAIN} ${LIB_NAME} -o ${EXE_NAME}

all: $(LIB_NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(LIB_NAME) ${EXE_NAME}

re: fclean all

.PHONY: all clean fclean re
