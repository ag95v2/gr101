
all:
	gcc main.c -I minilibx/ -I libft/includes -L libft -L minilibx/ -lft -lmlx -lXext -lX11 -lm 
