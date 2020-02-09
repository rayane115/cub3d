/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:49:58 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 16:46:43 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_fill_texture(char *buff, int i, t_all *data, char c)
{
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
}

void	ft_fill_map(char *buff, t_list **lst)
{
	t_list *new_elem;

	new_elem = ft_lstnew(del_space_str(buff));
	ft_lstadd_back(lst, new_elem);
}

void	ft_fill_color(char *buff, int i, int *color)
{
	i = i + 1;
	while (buff[i] == ' ')
		i++;
	*color = ft_atoi(&buff[i]) * 256 * 256;
	while (buff[i] != ',')
		i++;
	i++;
	*color += ft_atoi(&buff[i]) * 256;
	while (buff[i] != ',')
		i++;
	i++;
	*color += ft_atoi(&buff[i]);
}

void	ft_fill_resolution(char *buff, int i, t_all *data)
{
	while (buff[i] == ' ' || (buff[i] >= 'A' && buff[i] <= 'Z'))
		i++;
	data->resolution.x = ft_atoi(&buff[i]);
	while (buff[i] >= '0' && buff[i] <= '9')
		i = i + 1;
	i = i + 1;
	data->resolution.y = ft_atoi(&buff[i]);
	if (!data->resolution.x || !data->resolution.y)
		ft_printf("error\n");
}

void	ft_fill_my_struct(char *buff, t_all *data, t_list **lst)
{
	int i;

	i = 0;
	ft_delete_space(buff, &i);
	if (buff[i] == 'R')
		ft_fill_resolution(buff, i, data);
	else if (buff[i] == 'N' && buff[i + 1] == 'O')
		ft_fill_texture(buff, i, data, buff[i]);
	else if (buff[i] == 'S' && buff[i + 1] == 'O')
		ft_fill_texture(buff, i, data, buff[i + 1]);
	else if (buff[i] == 'W' && buff[i + 1] == 'E')
		ft_fill_texture(buff, i, data, buff[i]);
	else if (buff[i] == 'E' && buff[i + 1] == 'A')
		ft_fill_texture(buff, i, data, buff[i]);
	else if (buff[i] == 'S' && buff[i + 1] == ' ')
		ft_fill_texture(buff, i, data, buff[i]);
	else if (buff[i] == 'F')
		ft_fill_color(buff, i, &data->color.f);
	else if (buff[i] == 'C')
		ft_fill_color(buff, i, &data->color.c);
	else if (ft_strlen(buff))
		ft_fill_map(buff, lst);
}
