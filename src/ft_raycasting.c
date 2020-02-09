/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:14:24 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 18:33:34 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void		ft_raycast_four(t_all *data)
{
	while (data->raycast.hit == 0)
	{
		if (data->raycast.sidedistx < data->raycast.sidedisty)
		{
			data->raycast.sidedistx += data->raycast.deltadistx;
			data->raycast.mapx += data->raycast.stepx;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.sidedisty += data->raycast.deltadisty;
			data->raycast.mapy += data->raycast.stepy;
			data->raycast.side = 1;
		}
		if (data->texture.map[data->raycast.mapx][data->raycast.mapy] == '1')
			data->raycast.hit = 1;
	}
	ft_raycast_five(data);
}

void		ft_raycast_three(t_all *data)
{
	if (data->raycast.raydirx < 0)
	{
		data->raycast.stepx = -1;
		data->raycast.sidedistx = (data->raycast.rayposx -
		data->raycast.mapx) * data->raycast.deltadistx;
	}
	else
	{
		data->raycast.stepx = 1;
		data->raycast.sidedistx = (data->raycast.mapx + 1.0 -
		data->raycast.rayposx) * data->raycast.deltadistx;
	}
	if (data->raycast.raydiry < 0)
	{
		data->raycast.stepy = -1;
		data->raycast.sidedisty = (data->raycast.rayposy -
		data->raycast.mapy) * data->raycast.deltadisty;
	}
	else
	{
		data->raycast.stepy = 1;
		data->raycast.sidedisty = (data->raycast.mapy + 1.0 -
		data->raycast.rayposy) * data->raycast.deltadisty;
	}
}

void		ft_raycast_two(t_all *data)
{
	data->raycast.camerax = (2.0 * (float)data->raycast.x /
	(float)data->resolution.x) - 1.0;
	data->raycast.rayposx = data->raycast.posx;
	data->raycast.rayposy = data->raycast.posy;
	data->raycast.raydirx = data->raycast.dirx + data->raycast.planex *
	data->raycast.camerax;
	data->raycast.raydiry = data->raycast.diry + data->raycast.planey *
	data->raycast.camerax;
	data->raycast.mapx = (int)data->raycast.rayposx;
	data->raycast.mapy = (int)data->raycast.rayposy;
	data->raycast.deltadistx = sqrt(1 + (data->raycast.raydiry *
	data->raycast.raydiry) / (data->raycast.raydirx * data->raycast.raydirx));
	data->raycast.deltadisty = sqrt(1 + (data->raycast.raydirx *
	data->raycast.raydirx) / (data->raycast.raydiry * data->raycast.raydiry));
	data->raycast.hit = 0;
	ft_raycast_three(data);
}

void		ft_raycasting(t_all *data)
{
	int		(*print_pixel)[data->resolution.x][1];

	data->raycast.x = 0;
	data->raycast.y = 0;
	print_pixel = ft_print_image(data);
	while (data->raycast.x++ <= data->resolution.x)
	{
		ft_raycast_two(data);
		ft_raycast_four(data);
		while (data->raycast.y++ < data->raycast.drawend)
		{
			ft_raycast_six(data);
			*print_pixel[data->raycast.drawstart++][data->raycast.x] =
			data->raycast.color;
		}
		while (data->raycast.y < data->resolution.y)
		{
			data->raycast.r = data->resolution.y - data->raycast.y - 1;
			*print_pixel[data->raycast.r][data->raycast.x] = 0x0033FF;
			*print_pixel[data->raycast.drawstart++]
			[data->raycast.x] = 0x300FF33;
			data->raycast.y++;
		}
		data->spr.distwall[data->raycast.x] = data->raycast.perpwalldist;
	}
}
