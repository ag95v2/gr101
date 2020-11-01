NAME = fdf

MINILIBX_LINUX=minilibx
MINILIBX_MACOS=minilibx_macos

UNAME := $(shell uname)

SYSTEM=macos
ifeq ($(UNAME),"Linux")
	echo "Linux detected"
	SYSTEM=linux
endif

all: $(SYSTEM)
	@echo "Ok"

.PHONY: linux macos

linux:
	@echo "Compiling fdf for linux. If you use Macos, try 'make macos'"
	gcc main.c -I minilibx/ -I libft/includes -L libft -L minilibx/ -lft -lmlx -lXext -lX11 -lm  -o $(NAME)

macos:
	@echo "Compiling fdf for macos. If you use linux, try 'make linux'"
	gcc main.c -I minilibx_macos/ -I libft/includes -L libft -L minilibx_macos/ -lft -lmlx -lm  -framework OpenGL -framework AppKit -o $(NAME)
