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


LIBFT = -lmlx -framework OpenGL -framework AppKit\
		./libft/libft.a
CFLAGS =    -Wall -Wextra -Werror -g3
HEADER =    ft_cube3d.h

all : $(NAME)

#$(LIBFT) :
#	@(make -C libft)

$(NAME) : $(SRCS)
#	@(make -C libft)
	@(gcc $(CFLAGS) $(SRCS) $(LIBFT) -I $(HEADER) -o $(NAME))
	@(./$(NAME) map.cub)

clean:
	@(rm -f $(NAME))
#	make clean -C libft

lib :
	@(make re -C libft)
	@(make clean -C libft)

fclean: clean
#	make fclean -C libft

re : fclean all
