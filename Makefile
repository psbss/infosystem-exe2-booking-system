SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:%.c=%.o)
SRCS_DIR = src/
INCS = mylib.h
MAIN = $(SRCS_DIR)main.c
LIB_NAME = $(SRCS_DIR)MYLIB
EXE_NAME = ExeBooking
CC = gcc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
RM = rm

.c.o:
	$(CC) $(FLAGS) -c $< -o $@ -I ${INCS}

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	$(AR) $(LIB_NAME) $(OBJS)
	${CC} ${MAIN} ${LIB_NAME} -o ${EXE_NAME}

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(LIB_NAME) ${EXE_NAME}

re: fclean all

.PHONY: all clean fclean re
