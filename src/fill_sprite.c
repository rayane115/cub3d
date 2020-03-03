/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:14:33 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/26 18:28:18 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void		ft_free(t_all *all)
{
	if (all->spr.distwall)
		free(all->spr.distwall);
}

void		ft_sprites(t_all *all)
{
	int x;
	int y;
	int i;

	x = 0;
	i = 0;
	while (all->texture.map[x])
	{
		y = 0;
		while (all->texture.map[x][y])
		{
			if (all->texture.map[x][y] == '2')
			{
				all->sprites[i].coor = (t_dcoor){x + 0.5, y + 0.5};
				i++;
			}
			y++;
		}
		x++;
	}
}

void		get_color(t_all *all, int i)
{
	if (all->sprites[i].img.get_data[all->spr.texsp.x
			+ all->spr.texsp.y * all->sprites[i].img.w] != -16777216)
	{
		all->sprites[i].img.color =
			all->sprites[i].img.get_data[all->spr.texsp.x
			+ all->spr.texsp.y * all->sprites[i].img.w];
	}
	else
		all->sprites[i].img.color = 0x0;
}

void		sp_draw(t_all *all, int x, int i)
{
	int y;
	int d;

	y = all->spr.start.y;
	while (y < all->spr.end.y)
	{
		d = (y * 256 - all->resolution.y * 128 + all->spr.sph * 128);
		all->spr.texsp.y = (d * all->sprites[i].img.h / all->spr.sph) / 256;
		get_color(all, i);
		if (all->sprites[i].img.color != 0x0
			&& all->spr.trans.y < all->spr.distwall[x])
		{
			if (x >= 0 && x < all->resolution.x && y >= 0 && y <
			all->resolution.y)
				all->mlx.get_data[x + y * (all->mlx.size_line
				/ 4)] = all->sprites[i].img.color;
		}
		y++;
	}
}

void		init_sprites(t_all *all)
{
	int i;
	int x;

	i = 0;
	ft_sort(all);
	ft_sort_sp(all);
	while (i < all->spr.nbr)
	{
		sp_position(all, i);
		sp_dimension(all);
		x = all->spr.start.x;
		while (x < all->spr.end.x && x < all->resolution.x)
		{
			all->spr.texsp.x = (int)(256 * (x - (-all->spr.spw / 2 +
				all->spr.spscreen)) * all->sprites[i].img.w
				/ all->spr.spw) / 256;
			if (all->spr.trans.y > 0)
				sp_draw(all, x, i);
			x++;
		}
		i++;
	}
	ft_free(all);
}
