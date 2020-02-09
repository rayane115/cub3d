/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:14:49 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 16:44:57 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void		ft_delete_space(char *buff, int *i)
{
	while (buff[*i] == ' ')
		*i = *i + 1;
}

char		*del_space_str(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == ' ')
			j++;
	if (!(temp = ft_calloc(sizeof(char), i - j + 1)))
		exit(0);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			temp[j] = str[i];
			j++;
		}
	}
	temp[j] = '\0';
	return (temp);
}

void		convert_lst_to_char(t_all *data, t_list *lst)
{
	int		i;
	int		a;

	i = 0;
	if (!(data->texture.map = ft_calloc(sizeof(char *), ft_lstsize(lst) + 1)))
		exit(0);
	while (lst)
	{
		data->texture.map[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	data->texture.map[i] = NULL;
	i = 0;
	a = 0;
	while (data->texture.map[i])
	{
		while (data->texture.map[i][a])
		{
			if (data->texture.map[i][a] == '2')
				data->spr.nbr++;
			a++;
		}
		a = 0;
		i++;
	}
}

void		initall(t_all *data)
{
	ft_memset(data, 0, sizeof(t_all));
}

void		ft_open(char *av, t_all *data)
{
	char	*buff;
	t_list	**lst;
	int		fd;
	int		ret;

	lst = ft_calloc(sizeof(t_list), 1);
	*lst = NULL;
	buff = NULL;
	(void)data;
	fd = open(av, O_RDWR);
	while ((ret = get_next_line(fd, &buff) > 0))
	{
		ft_fill_my_struct(buff, data, lst);
		free(buff);
	}
	convert_lst_to_char(data, *lst);
	ft_lstclear(lst, free);
	free(lst);
	if (buff)
		free(buff);
	close(fd);
}
