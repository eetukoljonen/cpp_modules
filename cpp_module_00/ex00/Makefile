NAME = megaphone
SRC = megaphone.cpp
OBJ = megaphone.o
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(C_FLAGS) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(C_FLAGS) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
