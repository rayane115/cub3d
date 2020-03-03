/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:38:59 by rqouchic          #+#    #+#             */
/*   Updated: 2020/03/01 16:19:03 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	error_color(void)
{
	ft_printf("Error\ncolor\n");
	exit(0);
}

void	error_texture(void)
{
	ft_printf("Error\ntexture\n");
	exit(0);
}

void	error_map(void)
{
	ft_printf("Error\nmap\n");
	exit(0);
}

void	error_resolution(void)
{
	ft_printf("Error\nresolution\n");
	exit(0);
}

void	fichier_vide_and_reso_haute(t_all *data)
{
	if (data->resolution.x > 2560)
		data->resolution.x = 2558;
	if (data->resolution.y > 1440)
		data->resolution.y = 1440;
	if (data->raycast.presence_reso != 1 && data->raycast.presence_m != 1
	&& data->raycast.presence_c != 2 && data->raycast.presence_t != 5)
	{
		ft_printf("Error\nfichier vide");
		exit(0);
	}
}
