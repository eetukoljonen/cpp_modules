NAME = test
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC =  main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp Floor.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

