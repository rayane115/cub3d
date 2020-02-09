/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:55:59 by rqouchic          #+#    #+#             */
/*   Updated: 2020/02/09 17:13:43 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cube3d.h"

void		get_texture_no(t_all *data)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(data->raycast.mlx,
		data->texture.no, &data->raycast.textw_no, &data->raycast.texth_no)))
	{
		ft_printf("Error");
		exit(0);
	}
	data->raycast.text_no = (int *)mlx_get_data_addr(image,
	&bit_per_pixel, &x, &y);
}

void		get_texture_ea(t_all *data)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(data->raycast.mlx,
		data->texture.ea, &data->raycast.textw_ea, &data->raycast.texth_ea)))
	{
		ft_printf("Error");
		exit(0);
	}
	data->raycast.text_ea = (int *)mlx_get_data_addr(image,
	&bit_per_pixel, &x, &y);
}

void		get_texture_so(t_all *data)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(data->raycast.mlx,
		data->texture.so, &data->raycast.textw_so, &data->raycast.texth_so)))
	{
		ft_printf("Error");
		exit(0);
	}
	data->raycast.text_so = (int *)mlx_get_data_addr(image,
	&bit_per_pixel, &x, &y);
}

void		get_texture_we(t_all *data)
{
	void	*image;
	int		x;
	int		y;
	int		bit_per_pixel;

	if (!(image = mlx_xpm_file_to_image(data->raycast.mlx,
		data->texture.we, &data->raycast.textw_we, &data->raycast.texth_we)))
	{
		ft_printf("Error");
		exit(0);
	}
	data->raycast.text_we = (int *)mlx_get_data_addr(image,
	&bit_per_pixel, &x, &y);
}

t_mlx		get_texture_sprite(t_all *all)
{
	t_mlx	texture;
	void	*image;

	if (!(image = mlx_xpm_file_to_image(all->raycast.mlx,
		all->texture.sprite, &texture.w, &texture.h)))
	{
		ft_printf("Error");
		exit(0);
	}
	texture.get_data = (int *)mlx_get_data_addr(image, &texture.bits_per_pixel,
	&texture.size_line, &texture.endian);
	return (texture);
}
