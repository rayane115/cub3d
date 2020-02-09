/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:58:14 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 16:27:10 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void	ft_raycast_nine(t_all *data)
{
	if (data->raycast.drawend < 0)
		data->raycast.drawend = data->resolution.y;
	data->raycast.y = data->raycast.drawend;
}

void	ft_raycast_height(t_all *data)
{
	if (data->raycast.raydirx > 0 && !data->raycast.side)
	{
		data->raycast.p = (data->raycast.textw_ea * data->raycast.texy) +
		data->raycast.texx;
		data->raycast.color = data->raycast.text_ea[data->raycast.p];
	}
	if (data->raycast.raydirx < 0 && !data->raycast.side)
	{
		data->raycast.p = (data->raycast.textw_we * data->raycast.texy) +
		data->raycast.texx;
		data->raycast.color = data->raycast.text_we[data->raycast.p];
	}
}

void	ft_raycast_seven(t_all *data)
{
	if ((data->raycast.raydirx > 0 && data->raycast.side &&
	data->raycast.raydiry < 0) ||
	(data->raycast.side && data->raycast.raydiry < 0))
	{
		data->raycast.p = (data->raycast.textw_no * data->raycast.texy) +
		data->raycast.texx;
		data->raycast.color = data->raycast.text_no[data->raycast.p];
	}
	if ((data->raycast.raydirx > 0 && data->raycast.side &&
	data->raycast.raydiry > 0) ||
	(data->raycast.side && data->raycast.raydiry > 0))
	{
		data->raycast.p = (data->raycast.textw_so * data->raycast.texy) +
		data->raycast.texx;
		data->raycast.color = data->raycast.text_so[data->raycast.p];
	}
	ft_raycast_height(data);
}

void	ft_raycast_six(t_all *data)
{
	data->raycast.texnum =
	data->texture.map[data->raycast.mapx][data->raycast.mapy] - 1;
	if (data->raycast.side == 1)
		data->raycast.wallx = data->raycast.rayposx + ((data->raycast.mapy -
		data->raycast.rayposy + (1 - data->raycast.stepy) / 2) /
		data->raycast.raydiry) * data->raycast.raydirx;
	else
		data->raycast.wallx = data->raycast.rayposy +
		((data->raycast.mapx - data->raycast.rayposx +
		(1 - data->raycast.stepx) / 2) /
		data->raycast.raydirx) * data->raycast.raydiry;
	data->raycast.wallx -= floor((data->raycast.wallx));
	data->raycast.texx = (int)(data->raycast.wallx * texwidth);
	if (data->raycast.side == 0 && data->raycast.raydirx > 0)
		data->raycast.texx = texwidth - data->raycast.texx - 1;
	if (data->raycast.side == 1 && data->raycast.raydiry < 0)
		data->raycast.texx = texwidth - data->raycast.texx - 1;
	data->raycast.texy = (data->raycast.y * 2 -
	data->resolution.y + data->raycast.hauteurligne) * (texheight / 2) /
	data->raycast.hauteurligne;
	ft_raycast_seven(data);
}

void	ft_raycast_five(t_all *data)
{
	if (data->raycast.side == 0)
		data->raycast.perpwalldist = fabs((data->raycast.mapx -
		data->raycast.rayposx + (1 - data->raycast.stepx) / 2) /
		data->raycast.raydirx);
	else
		data->raycast.perpwalldist = fabs((data->raycast.mapy -
		data->raycast.rayposy + (1 - data->raycast.stepy) / 2) /
		data->raycast.raydiry);
	data->raycast.hauteurligne = fabs((data->resolution.y /
	data->raycast.perpwalldist));
	data->raycast.drawstart = (int)(-data->raycast.hauteurligne /
	2 + data->resolution.y / 2);
	data->raycast.drawend = (int)(data->raycast.hauteurligne / 2 +
	data->resolution.y / 2);
	if (data->raycast.drawstart < 0)
		data->raycast.drawstart = 0;
	if (data->raycast.drawend >= data->resolution.y)
		data->raycast.drawend = data->resolution.y - 1;
	data->raycast.y = data->raycast.drawstart;
}
