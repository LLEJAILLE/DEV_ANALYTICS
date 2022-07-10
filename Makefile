##
## EPITECH PROJECT, 2022
## B-MAT-100-NCY-1-1-104intersection-hugo.meunier
## File description:
## Makefile
##


SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = dev_analytics

CFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ)
	rm -f $(OBJ)
	rm -f *~

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *~

re : fclean all
