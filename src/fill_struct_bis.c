/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:49:58 by rqouchic          #+#    #+#             */
/*   Updated: 2020/03/01 16:24:30 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_fill_texture(char *buff, int i, t_all *data, char c)
{
	int	a;

	a = 0;
	i = i + 2;
	while (buff[i] == ' ')
		i = i + 1;
	if (c == 'N')
		data->texture.no = ft_strdup(&buff[i]);
	else if (c == 'O')
		data->texture.so = ft_strdup(&buff[i]);
	else if (c == 'W')
		data->texture.we = ft_strdup(&buff[i]);
	else if (c == 'E')
		data->texture.ea = ft_strdup(&buff[i]);
	else if (c == 'S')
		data->texture.sprite = ft_strdup(&buff[i]);
	data->raycast.presence_t++;
	while (buff[a])
		a++;
	a--;
	if (buff[a] != 'm' && buff[a] != 'M')
	{
		error_texture();
	}
}

void	ft_fill_map(char *buff, t_list **lst, t_all *data)
{
	t_list *new_elem;

	if (data->raycast.presence_reso != 1)
		error_resolution();
	if (data->raycast.presence_t != 5)
		error_texture();
	data->raycast.presence_m = 1;
	new_elem = ft_lstnew(del_space_str(buff));
	ft_lstadd_back(lst, new_elem);
}

void	ft_fill_color(t_all *data, char *buff, int i, int *color)
{
	ft_error_color_bis(buff);
	i = i + 1;
	while (buff[i] == ' ')
		i++;
	if (ft_atoi(&buff[i]) < 0 || ft_atoi(&buff[i]) > 255)
		error_color();
	*color = ft_atoi(&buff[i]) * 256 * 256;
	while (buff[i] != ',')
		i++;
	i++;
	if (ft_atoi(&buff[i]) < 0 || ft_atoi(&buff[i]) > 255)
		error_color();
	*color += ft_atoi(&buff[i]) * 256;
	while (buff[i] != ',')
		i++;
	i++;
	if (ft_atoi(&buff[i]) < 0 || ft_atoi(&buff[i]) > 255)
		error_color();
	*color += ft_atoi(&buff[i]);
	data->raycast.presence_c++;
}

void	ft_fill_resolution(char *buff, int i, t_all *data)
{
	data->resolution.a = 1;
	while (buff[data->resolution.a])
	{
		if ((buff[data->resolution.a] < '0' || buff[data->resolution.a] > '9')
		&& buff[data->resolution.a] != ' ' && buff[data->resolution.a] != 'R')
		{
			ft_printf("Error\nresolution\n");
			exit(0);
		}
		data->resolution.a++;
	}
	while (buff[i] == ' ' || (buff[i] >= 'A' && buff[i] <= 'Z'))
		i++;
	data->resolution.x = ft_atoi(&buff[i]);
	while (buff[i] >= '0' && buff[i] <= '9')
		i = i + 1;
	i = i + 1;
	data->resolution.y = ft_atoi(&buff[i]);
	while (buff[i] >= '0' && buff[i] <= '9')
		i = i + 1;
	i = i + 1;
	data->resolution.au = ft_atoi(&buff[i]);
	data->raycast.presence_reso++;
	if (!data->resolution.x || !data->resolution.y || data->resolution.au != 0)
		error_resolution();
}

void	ft_fill_my_struct(char *buff, t_all *data, t_list **lst)
{
	ft_delete_space(buff, &data->ind.b);
	if (buff[data->ind.b] == 'R')
		ft_fill_resolution(buff, data->ind.b, data);
	else if (buff[data->ind.b] == 'N' && buff[data->ind.b + 1] == 'O')
		ft_fill_texture(buff, data->ind.b, data, buff[data->ind.b]);
	else if (buff[data->ind.b] == 'S' && buff[data->ind.b + 1] == 'O')
		ft_fill_texture(buff, data->ind.b, data, buff[data->ind.b + 1]);
	else if (buff[data->ind.b] == 'W' && buff[data->ind.b + 1] == 'E')
		ft_fill_texture(buff, data->ind.b, data, buff[data->ind.b]);
	else if (buff[data->ind.b] == 'E' && buff[data->ind.b + 1] == 'A')
		ft_fill_texture(buff, data->ind.b, data, buff[data->ind.b]);
	else if (buff[data->ind.b] == 'S' && buff[data->ind.b + 1] == ' ')
		ft_fill_texture(buff, data->ind.b, data, buff[data->ind.b]);
	else if (buff[data->ind.b] == 'F')
		ft_fill_color(data, buff, data->ind.b, &data->color.f);
	else if (buff[data->ind.b] == 'C')
		ft_fill_color(data, buff, data->ind.b, &data->color.c);
	else if (ft_strlen(buff))
		ft_fill_map(buff, lst, data);
	else if (*lst)
	{
		ft_verif(data);
		error_map();
		exit(0);
	}
}
