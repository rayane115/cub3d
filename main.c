/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:52:12 by rqouchic          #+#    #+#             */
/*   Updated: 2020/03/01 19:46:20 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_cube3d.h"

int			ft_cub(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (len - 4 < 0)
		len = 0;
	else
		len = len - 4;
	if ((ft_strncmp(argv + len, ".cub", 4)))
		return (1);
	return (0);
}

int			*ft_print_image(t_all *data)
{
	int		endian;

	data->raycast.img_ptr = mlx_new_image(data->raycast.mlx,
	data->resolution.x, data->resolution.y);
	data->mlx.get_data = (int *)mlx_get_data_addr(data->raycast.img_ptr,
	&data->mlx.bits_per_pixel,
	&data->mlx.size_line, &endian);
	return (data->mlx.get_data);
}

void		ft_invers_map(t_all *data)
{
	while (data->texture.map[data->m.j])
	{
		while (data->texture.map[data->m.j][data->m.i++])
			data->m.a++;
		data->m.i = 0;
		data->m.j++;
	}
	data->m.j--;
	if (!(data->raycast.mapcopy = ft_calloc(sizeof(char *), data->m.a + 1)))
		exit(0);
	while (data->m.j != -1)
	{
		data->raycast.mapcopy[data->m.k++] = ft_strdup(
			data->texture.map[data->m.j]);
		free(data->texture.map[data->m.j--]);
	}
	data->raycast.mapcopy[data->m.k] = NULL;
	data->m.j = 0;
	data->m.k = 0;
	while (data->texture.map[data->m.j])
	{
		data->texture.map[data->m.j++] = ft_strdup(
			data->raycast.mapcopy[data->m.k]);
		free(data->raycast.mapcopy[data->m.k++]);
	}
}

void		lance_fonction(t_all *data, char *av, int ac)
{
	data->raycast.mlx = mlx_init();
	data->raycast.window = mlx_new_window(data->raycast.mlx,
	data->resolution.x, data->resolution.y, "Title");
	get_texture_all(data);
	if (av && !ft_strncmp(av, "--save", 10))
		ft_bmpinit(data);
	check_ac(ac);
	mlx_hook(data->raycast.window, 2, (1L << 0), &ft_push, data);
	mlx_hook(data->raycast.window, 3, (1L << 1), &ft_depush, data);
	mlx_hook(data->raycast.window, 17, 0, &ft_croix, data);
	mlx_loop_hook(data->raycast.mlx, &ft_bouge, data);
	mlx_loop(data->raycast.mlx);
}

int			main(int ac, char **av)
{
	t_all	*data;

	if (ac == 1 || ft_cub(av[1]))
		error_arg();
	data = (t_all *)malloc(sizeof(t_all));
	initall(data);
	ft_open(av[1], data);
	fichier_vide_and_reso_haute(data);
	if (data->raycast.presence_reso != 1)
		error_resolution();
	if (data->raycast.presence_t != 5)
		error_texture();
	if (data->raycast.presence_c != 2)
		error_color();
	if (data->raycast.presence_m != 1)
		error_map();
	ft_map_error_bis(data);
	ft_invers_map(data);
	if (!(data->sprites = (t_sprites*)malloc(sizeof(t_sprites) *
	data->spr.nbr)))
		return (-1);
	ft_position_error_text(data);
	lance_fonction(data, av[2], ac);
	return (0);
}
