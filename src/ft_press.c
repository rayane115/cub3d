/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:18:15 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/26 17:39:56 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

int			ft_push(int key, t_all *data)
{
	if (key == 13)
		data->mouv.avancer = 1;
	if (key == 1)
		data->mouv.reculer = 1;
	if (key == 0)
		data->mouv.gauche = 1;
	if (key == 2)
		data->mouv.droite = 1;
	if (key == 14 || key == 124)
	{
		data->mouv.tourner = 1;
		data->mouv.vitrotation = -0.1;
	}
	if (key == 12 || key == 123)
	{
		data->mouv.tourner = 1;
		data->mouv.vitrotation = 0.1;
	}
	data->mouv.bool = 1;
	return (0);
}

int			ft_depush(int key, t_all *data)
{
	if (key == 13)
		data->mouv.avancer = 0;
	if (key == 1)
		data->mouv.reculer = 0;
	if (key == 0)
		data->mouv.gauche = 0;
	if (key == 2)
		data->mouv.droite = 0;
	if (key == 14 || key == 124)
		data->mouv.tourner = 0;
	if (key == 12 || key == 123)
		data->mouv.tourner = 0;
	if (key == 53)
	{
		ft_printf("game over esc\n");
		exit(0);
	}
	return (0);
}

void		get_texture_all(t_all *data)
{
	int		i;

	i = -1;
	get_texture_no(data);
	get_texture_so(data);
	get_texture_ea(data);
	get_texture_we(data);
	get_texture_sprite(data);
	while (++i < data->spr.nbr)
	{
		data->sprites[i].img = get_texture_sprite(data);
	}
}
