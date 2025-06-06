
CC = cc
W = -Wall -Wextra -Werror 
TARGET =  so_long
INCLUDES = -I. -Iget_next_line -Iminilibx-linux -Ift_printf 
MLX_DIR = /minilibx-linux
MLX = -L.$(MLX_DIR) -lmlx -lm -lX11 -lXext


SRCS = so_long.c ft_arr_.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_char.c \
ft_printf/ft_format.c ft_printf/ft_puthex_x.c ft_printf/printf.c   ft_graphics.c  ft_key_a_d_w_s.c 	ft_chek.c \
ft_chek_tow.c ft_chek_three.c ft_finish_win.c ft_key_aa_dd_ss_ww.c ft_ex.c  ft_find.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET):	$(OBJS)
	$(CC)  $(W) $(OBJS)  $(INCLUDES)  $(MLX) -o $(TARGET) 
%.o: %.c
	$(CC)  $(W) -I/usr/include -Imlx_linux -O3 -c $< -o $@
clean:
	rm	-f	$(OBJS)
fclean:
	rm	-f	$(TARGET) $(OBJS)
re:
	$(MAKE) fclean
	$(MAKE)	all
.PHONY: all clean fclean re

