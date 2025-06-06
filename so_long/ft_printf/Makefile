NAME = libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra -Werror 
SRCS = printf.c ft_format.c ft_char.c ft_puthex_x.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f  $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
