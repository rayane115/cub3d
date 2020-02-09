/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:36:48 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 16:37:10 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

float		ft_fpower(float nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_fpower(nb, power - 1));
}

void		ft_sort(t_all *all)
{
	int i;

	i = 0;
	while (i < all->spr.nbr)
	{
		all->sprites[i].ordre = i;
		all->sprites[all->sprites[i].ordre].dist = ft_fpower(all->raycast.posx
			- all->sprites[all->sprites[i].ordre].coor.x, 2) +
			ft_fpower(all->raycast.posy -
			all->sprites[all->sprites[i].ordre].coor.y, 2);
		i++;
	}
}

void		ft_sort_sp(t_all *all)
{
	int tmp;
	int i;

	i = 0;
	while (i + 1 < all->spr.nbr)
	{
		if (all->sprites[all->sprites[i].ordre].dist
			< all->sprites[all->sprites[i + 1].ordre].dist)
		{
			tmp = all->sprites[i].ordre;
			all->sprites[i].ordre = all->sprites[i + 1].ordre;
			all->sprites[i + 1].ordre = tmp;
			ft_sort_sp(all);
		}
		i++;
	}
}

void		sp_position(t_all *all, int i)
{
	double invdet;

	all->spr.camsp.x = all->sprites[all->sprites[i].ordre].coor.x
		- all->raycast.posx;
	all->spr.camsp.y = all->sprites[all->sprites[i].ordre].coor.y
		- all->raycast.posy;
	invdet = 1.0 / (all->raycast.planex * all->raycast.diry
		- all->raycast.planey * all->raycast.dirx);
	all->spr.trans.x = invdet * (all->raycast.diry *
		all->spr.camsp.x - all->raycast.dirx * all->spr.camsp.y);
	all->spr.trans.y = invdet * (-all->raycast.planey *
		all->spr.camsp.x + all->raycast.planex * all->spr.camsp.y);
	all->spr.spscreen = (int)((all->resolution.x / 2) *
		(1.0 + all->spr.trans.x / all->spr.trans.y));
}

void		sp_dimension(t_all *all)
{
	all->spr.sph = abs((int)(all->resolution.y / all->spr.trans.y));
	all->spr.start.y = -all->spr.sph / 2 + all->resolution.y / 2;
	if (all->spr.start.y < 0)
		all->spr.start.y = 0;
	all->spr.end.y = all->spr.sph / 2 + all->resolution.y / 2;
	if (all->spr.end.y >= all->resolution.y)
		all->spr.end.y = all->resolution.y - 1;
	all->spr.spw = abs((int)(all->resolution.y / all->spr.trans.y));
	all->spr.start.x = -all->spr.spw / 2 + all->spr.spscreen;
	if (all->spr.start.x < 0)
		all->spr.start.x = 0;
	all->spr.end.x = all->spr.spw / 2 + all->spr.spscreen;
	if (all->spr.end.x >= all->resolution.x)
		all->spr.end.x = all->resolution.x - 1;
}
