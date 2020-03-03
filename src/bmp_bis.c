/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:55:21 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/26 20:01:14 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	initmlx(t_all *all)
{
	if (!(all->raycast.img_ptr = mlx_new_image(all->raycast.mlx,
			all->resolution.x, all->resolution.y)))
	{
		ft_printf("Error\nmlx_new_image");
		exit(0);
	}
	if (!(all->mlx.get_data = (int *)mlx_get_data_addr(all->raycast.img_ptr,
	&all->mlx.bits_per_pixel,
	&all->mlx.size_line, &all->mlx.endian)))
	{
		ft_printf("Error\nmlx_get_data_addr");
		exit(0);
	}
}

void	ft_bmpinit(t_all *all)
{
	initmlx(all);
	if (!(all->spr.distwall = ft_calloc(sizeof(double*), all->resolution.x)))
	{
		ft_printf("Error\nScreen");
		exit(0);
	}
	ft_raycasting(all);
	ft_sprites(all);
	init_sprites(all);
	ft_bmp(all);
	exit(0);
}

void	check_ac(int ac)
{
	if (ac < 2 || ac >= 3)
	{
		ft_printf("Error\nd'arguments");
		exit(0);
	}
}

void	error_arg(void)
{
	ft_printf("Error\nd'arguments");
	exit(0);
}

int		ft_croix(t_all *data)
{
	data->resolution.x = data->resolution.x + 0;
	ft_printf("GAME OVER");
	exit(0);
	return (0);
}
