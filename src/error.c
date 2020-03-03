/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:23:49 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/26 15:05:41 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_position_error4(t_all *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->texture.map[j])
	{
		i = 0;
		while (data->texture.map[j][i])
		{
			if ((data->texture.map[0][i] != '1' && j == 0) ||
			data->texture.map[j][0] != '1' ||
			data->texture.map[j][ft_strlen(data->texture.map[j]) - 1]
			!= '1')
				error_map();
			i++;
		}
		j++;
	}
	j--;
	i = 0;
	while (data->texture.map[j][i])
	{
		if (data->texture.map[j][i++] != '1')
			error_map();
	}
}

void	ft_position_error3(t_all *data, int j, int i)
{
	if (data->texture.map[j][i] == 'N')
	{
		data->raycast.dirx = 1;
		data->raycast.diry = 0;
	}
	else if (data->texture.map[j][i] == 'S')
	{
		data->raycast.dirx = -1;
		data->raycast.diry = 0;
	}
	else if (data->texture.map[j][i] == 'E')
	{
		data->raycast.dirx = 0;
		data->raycast.diry = 1;
	}
	else if (data->texture.map[j][i] == 'W')
	{
		data->raycast.dirx = 0;
		data->raycast.diry = -1;
	}
	data->raycast.planex = -0.66 * data->raycast.diry;
	data->raycast.planey = 0.66 * data->raycast.dirx;
}

void	ft_position_error2(t_all *data)
{
	while (data->texture.map[data->ind.j])
	{
		while (data->texture.map[data->ind.j][data->ind.i++])
		{
			if (data->texture.map[data->ind.j][data->ind.i] == 'N' ||
			data->texture.map[data->ind.j][data->ind.i] == 'S' ||
			data->texture.map[data->ind.j][data->ind.i] == 'E' ||
			data->texture.map[data->ind.j][data->ind.i] == 'W')
			{
				data->ind.a = data->ind.i;
				break ;
			}
		}
		if (data->texture.map[data->ind.j][data->ind.i] == 'N' ||
		data->texture.map[data->ind.j][data->ind.i] == 'S' ||
			data->texture.map[data->ind.j][data->ind.i] == 'E' ||
			data->texture.map[data->ind.j][data->ind.i] == 'W')
			break ;
		data->ind.i = 0;
		data->ind.j++;
	}
	data->raycast.posx = (float)data->ind.j + 0.5;
	data->raycast.posy = (float)data->ind.a + 0.5;
	ft_position_error3(data, data->ind.j, data->ind.a);
	ft_position_error4(data);
}

void	ft_position_error1(t_all *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->texture.map[j])
	{
		while (data->texture.map[j][i])
		{
			if (data->texture.map[j][i] == 'N' || data->texture.map[j][i] == 'S'
			|| data->texture.map[j][i] == 'E' || data->texture.map[j][i] == 'W')
				data->raycast.presence++;
			i++;
		}
		i = 0;
		j++;
	}
	if (data->raycast.presence == 0 || data->raycast.presence > 1)
		error_map();
}

void	ft_position(t_all *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->texture.map[j])
	{
		while (data->texture.map[j][i])
		{
			if (data->texture.map[j][i] != '1' && data->texture.map[j][i]
			!= '0' && data->texture.map[j][i] != '2' &&
			data->texture.map[j][i] != 'N' && data->texture.map[j][i]
			!= 'S' && data->texture.map[j][i] != 'E' && data->texture.map[j][i]
			!= 'W')
				error_map();
			i++;
		}
		i = 0;
		j++;
	}
	ft_position_error1(data);
	ft_position_error2(data);
}
