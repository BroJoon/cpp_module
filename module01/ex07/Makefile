NAME = replace

CFLAGS = -Wall -Werror -Wextra

CC = clang++

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re