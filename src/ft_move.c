/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:20:27 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 17:12:54 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_bouge_four(t_all *data)
{
	if (data->mouv.droite)
	{
		if (data->texture.map[(int)(data->raycast.posx +
		data->raycast.planex * data->mouv.vitmarche)][(int)(
			data->raycast.posy)] == '0')
			data->raycast.posx += data->raycast.planex * data->mouv.vitmarche;
		if (data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy +
			data->raycast.planey * data->mouv.vitmarche)] == '0')
			data->raycast.posy += data->raycast.planey * data->mouv.vitmarche;
	}
	if (data->mouv.gauche)
	{
		if (data->texture.map[(int)(data->raycast.posx -
		data->raycast.planex *
		data->mouv.vitmarche)][(int)(data->raycast.posy)] == '0')
			data->raycast.posx -= data->raycast.planex * data->mouv.vitmarche;
		if (data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy -
			data->raycast.planey * data->mouv.vitmarche)] == '0')
			data->raycast.posy -= data->raycast.planey * data->mouv.vitmarche;
	}
}

void	ft_bouge_three(t_all *data)
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

void	ft_bouge_two(t_all *data)
{
	data->mouv.vitmarche = 0.2;
	if (data->mouv.avancer)
	{
		if (data->texture.map[(int)(data->raycast.posx + data->raycast.dirx *
		data->mouv.vitmarche)][(int)(data->raycast.posy)] == '0')
			data->raycast.posx += data->raycast.dirx * data->mouv.vitmarche;
		if (data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy + data->raycast.diry *
			data->mouv.vitmarche)] == '0')
			data->raycast.posy += data->raycast.diry * data->mouv.vitmarche;
	}
	if (data->mouv.reculer)
	{
		if (data->texture.map[(int)(data->raycast.posx -
		data->raycast.dirx * data->mouv.vitmarche)][(int)(
			data->raycast.posy)] == '0')
			data->raycast.posx -= data->raycast.dirx * data->mouv.vitmarche;
		if (data->texture.map[(int)(data->raycast.posx)][(int)(
			data->raycast.posy - data->raycast.diry *
			data->mouv.vitmarche)] == '0')
			data->raycast.posy -= data->raycast.diry * data->mouv.vitmarche;
	}
}

int		ft_bouge(t_all *data)
{
	ft_bouge_two(data);
	ft_bouge_three(data);
	ft_bouge_four(data);
	data->spr.distwall = ft_calloc(sizeof(double*), data->resolution.x);
	ft_raycasting(data);
	ft_sprites(data);
	init_sprites(data);
	mlx_put_image_to_window(data->raycast.mlx,
	data->raycast.window, data->raycast.img_ptr, 0, 0);
	mlx_destroy_image(data->raycast.mlx, data->raycast.img_ptr);
	return (0);
}
