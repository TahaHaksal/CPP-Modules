CC = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

NAME = account

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
