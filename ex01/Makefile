CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = phonebook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
