/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:20:27 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/24 20:28:30 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

int			ft_dontmove(t_all *data)
{
	if ((data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy)] == '1') ||
			(data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy)] == '2'))
		return (0);
	if ((data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy)] == '1') ||
			(data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy)] == '2'))
		return (0);
	return (1);
}

void		ft_bouge_four(t_all *data)
{
	double	tmp1;
	double	tmp2;

	tmp1 = data->raycast.posx;
	tmp2 = data->raycast.posy;
	if (data->mouv.droite)
	{
		data->raycast.posx += data->raycast.planex * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posx = tmp1;
		data->raycast.posy += data->raycast.planey * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posy = tmp2;
	}
	if (data->mouv.gauche)
	{
		data->raycast.posx -= data->raycast.planex * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posx = tmp1;
		data->raycast.posy -= data->raycast.planey * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posy = tmp2;
	}
}

void		ft_bouge_three(t_all *data)
{
	if (data->mouv.tourner)
	{
		data->raycast.olddirx = data->raycast.dirx;
		data->raycast.dirx = data->raycast.dirx * cos(
			-data->mouv.vitrotation) -
			data->raycast.diry * sin(-data->mouv.vitrotation);
		data->raycast.diry = data->raycast.olddirx *
		sin(-data->mouv.vitrotation) +
		data->raycast.diry * cos(-data->mouv.vitrotation);
		data->raycast.oldplanex = data->raycast.planex;
		data->raycast.planex = data->raycast.planex *
		cos(-data->mouv.vitrotation) -
		data->raycast.planey * sin(-data->mouv.vitrotation);
		data->raycast.planey = data->raycast.oldplanex *
		sin(-data->mouv.vitrotation) +
		data->raycast.planey * cos(-data->mouv.vitrotation);
	}
}

void		ft_bouge_two(t_all *data)
{
	double	tmp1;
	double	tmp2;

	tmp1 = data->raycast.posx;
	tmp2 = data->raycast.posy;
	data->mouv.vitmarche = 0.2;
	if (data->mouv.avancer)
	{
		data->raycast.posx += data->raycast.dirx * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posx = tmp1;
		data->raycast.posy += data->raycast.diry * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posy = tmp2;
	}
	if (data->mouv.reculer)
	{
		data->raycast.posx -= data->raycast.dirx * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posx = tmp1;
		data->raycast.posy -= data->raycast.diry * data->mouv.vitmarche;
		if (!ft_dontmove(data))
			data->raycast.posy = tmp2;
	}
}

int			ft_bouge(t_all *data)
{
	ft_bouge_two(data);
	ft_bouge_three(data);
	ft_bouge_four(data);
	if (!(data->spr.distwall = ft_calloc(sizeof(double*), data->resolution.x)))
		return (-1);
	ft_raycasting(data);
	ft_sprites(data);
	init_sprites(data);
	mlx_put_image_to_window(data->raycast.mlx,
	data->raycast.window, data->raycast.img_ptr, 0, 0);
	mlx_destroy_image(data->raycast.mlx, data->raycast.img_ptr);
	return (0);
}
