NAME = Cub3D
SRCS = 	main.c\
		src/fill_struct.c\
		src/fill_struct_bis.c\
		src/ft_raycasting.c\
		src/ft_press.c\
		src/ft_move.c\
		src/fill_texture.c\
		src/fill_sprite.c\
		src/ft_raycasting_utils.c\
		src/fill_sprite_utils.c\
		src/error.c\
		src/error_base.c\
		src/error_bis.c\
		src/bmp.c\
		src/bmp_bis.c\


LIBFT = -lmlx -framework OpenGL -framework AppKit\
		./libft/libft.a
CFLAGS =    -Wall -Wextra -Werror -g3
HEADER =    ft_cube3d.h

all : $(NAME)

$(LIBFT) :
	@(make -C libft)

$(NAME) : $(SRCS)
	@(make -C libft)
	@(gcc $(CFLAGS) $(SRCS) $(LIBFT) -I $(HEADER) -o $(NAME))

clean:
	@echo "Clean"
	@(make clean -C ./libft/)

fclean:	clean
	@echo "Fclean"
	@(make fclean -C ./libft/)
	@(rm -rf $(NAME))
	@(rm -rf Cub3D.dSYM)

re:	fclean all

.PHONY:	all clean fclean re
