/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:52:12 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 18:33:54 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_cube3d.h"

int			(*ft_print_image(t_all *data))[][1]
{
	int		endian;
	int		(*print_pixel)[data->resolution.x][1];

	data->raycast.img_ptr = mlx_new_image(data->raycast.mlx,
	data->resolution.x, data->resolution.y);
	data->mlx.get_data = (int *)mlx_get_data_addr(data->raycast.img_ptr,
	&data->mlx.bits_per_pixel,
	&data->mlx.size_line, &endian);
	print_pixel = (void *)data->mlx.get_data;
	return (print_pixel);
}

void		lance_fonction(t_all *data)
{
	data->raycast.mlx = mlx_init();
	data->raycast.window = mlx_new_window(data->raycast.mlx,
	data->resolution.x, data->resolution.y, "Title");
	get_texture_all(data);
	mlx_hook(data->raycast.window, 2, (1L << 0), &ft_push, data);
	mlx_hook(data->raycast.window, 3, (1L << 1), &ft_depush, data);
	mlx_loop_hook(data->raycast.mlx, &ft_bouge, data);
	mlx_loop(data->raycast.mlx);
}

int			main(int ac, char **av)
{
	t_all	*data;

	data = (t_all *)malloc(sizeof(t_all));
	initall(data);
	if (!ac)
		return (0);
	ft_open(av[1], data);
	if (!(data->sprites = (t_sprites*)malloc(sizeof(t_sprites) *
	data->spr.nbr)))
		return (-1);
	data->raycast.posx = 22;
	data->raycast.posy = 11.5;
	data->raycast.dirx = -1;
	data->raycast.diry = 0;
	data->raycast.planex = 0;
	data->raycast.planey = 0.60;
	data->resolution.x = 1000;
	data->resolution.y = 1000;
	lance_fonction(data);
	return (0);
}
