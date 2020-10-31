
all:
	gcc main.c -I minilibx/ -L minilibx/ -lmlx -lXext -lX11 -lm
