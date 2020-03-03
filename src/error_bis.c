/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:55:14 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/26 19:32:54 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_verif(t_all *data)
{
	if (data->raycast.presence_reso != 1)
		error_resolution();
	if (data->raycast.presence_t != 5)
		error_texture();
	if (data->raycast.presence_c != 2)
		error_color();
	if (data->raycast.presence_m != 1)
		error_map();
}

void	ft_position_error_text(t_all *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->texture.map[j][i])
		i++;
	i--;
	if (data->texture.map[j][i] == 'm')
		error_texture();
	ft_position(data);
}

void	ft_error_color_bis(char *buff)
{
	int	a;
	int	d;
	int	virgul;

	a = 1;
	d = 0;
	virgul = 0;
	while (buff[d++])
		if (buff[d] == ',')
			virgul++;
	if (virgul != 2)
		error_color();
	while (buff[a])
	{
		if (buff[a] != ',' && buff[a] != ' '
		&& (buff[a] < '0' || buff[a] > '9'))
			error_color();
		a++;
	}
}

void	ft_map_error_bis(t_all *data)
{
	int	j;
	int	i;
	int	diff;

	i = 0;
	j = 0;
	diff = 0;
	while (data->texture.map[++j])
	{
		i = ft_strlen(data->texture.map[j]);
		diff = (ft_strlen(data->texture.map[j - 1])) - 1 - i;
		check_diff(data, i, j, diff);
	}
}

void	check_diff(t_all *data, int i, int j, int diff)
{
	if (diff > 0)
	{
		while (diff + 1)
		{
			if (data->texture.map[j - 1][i + diff] != '1')
			{
				data->texture.map[j - 1][i + diff] = 'X';
				error_map();
			}
			diff--;
		}
	}
	else if (diff < 0)
	{
		while (data->texture.map[j][i + diff + 1])
		{
			if (data->texture.map[j][i + diff + 1] != '1')
			{
				data->texture.map[j][i + diff + 1] = 'P';
				error_map();
			}
			diff++;
		}
	}
}
