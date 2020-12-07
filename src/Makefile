SRCS = \
	lib.c \
	inquiry.c \

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

all: $(LIB_NAME)

link: all
	${CC} ${MAIN} ${LIB_NAME} -o ${EXE_NAME}

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(LIB_NAME) ${EXE_NAME}

re: fclean all

.PHONY: link all clean fclean re
