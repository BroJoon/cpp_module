NAME = convert

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Convert.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
