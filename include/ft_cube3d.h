/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:55:24 by rqouchic          #+#    #+#             */
/*   Updated: 2020/03/01 16:32:49 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define NUMSPRITES 19

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_dcoor
{
	double			x;
	double			y;
}					t_dcoor;

typedef	struct		s_resolution
{
	int				x;
	int				y;
	int				au;
	int				a;
}					t_resolution;

typedef	struct		s_color
{
	int				f;
	int				c;
}					t_color;

typedef	struct		s_image
{
	void			*image;
	int				*bits_per_pixel;
	int				*size_line;
	int				*endian;
}					t_image;

typedef	struct		s_mouv
{
	int				avancer;
	int				reculer;
	int				tourner;
	int				droite;
	int				gauche;
	float			vitmarche;
	float			vitrotation;
	int				bool;

}					t_mouv;

typedef	struct		s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	char			**map;
}					t_texture;

typedef	struct		s_raycast
{
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
	float			planex;
	float			planey;
	int				w;
	int				h;
	float			deltadistx;
	float			deltadisty;
	int				x;
	int				y;
	float			camerax;
	float			rayposx;
	float			rayposy;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	float			sidedistx;
	float			sidedisty;
	int				stepx;
	int				stepy;
	int				hit;
	float			side;
	float			perpwalldist;
	int				hauteurligne;
	int				drawstart;
	int				drawend;
	float			olddirx;
	float			oldplanex;
	void			*mlx;
	void			*window;
	int				presence;
	int				presence_reso;
	int				presence_t;
	char			**mapcopy;
	void			*img_texture;
	void			*img_ptr;
	void			*mlx_get_data;
	int				bits_per_pixel;
	int				endian;
	int				mlx_size_line;
	int				presence_c;
	int				presence_m;
	int				textw_no;
	int				texth_no;
	int				textw_so;
	int				texth_so;
	int				textw_ea;
	int				texth_ea;
	int				textw_we;
	int				texth_we;
	int				textw_sprite;
	int				texth_sprite;
	int				*text_no;
	int				*text_so;
	int				*text_ea;
	int				*text_we;
	int				*text_sprite;
	int				texnum;
	int				color;
	float			wallx;
	int				texx;
	int				texy;
	int				bit_per_pixel;
	int				p;
	int				r;
}					t_raycast;

typedef	struct		s_spr
{
	int				nbr;
	double			*sp_distance;
	int				stripe;
	int				*sp_order;
	double			spritex;
	double			spritey;
	double			inv_det;
	double			trans_x;
	double			trans_y;
	int				sp_screen;
	int				sp_h;
	int				sp_w;
	int				draw_startx;
	int				draw_starty;
	int				tsp_x;
	int				tsp_y;
	int				draw_endy;
	int				draw_endx;
	double			*distbuf;
	int				color;
	int				bit_pix;
	int				size_line;
	int				presence_r;
	int				nbsp;
	t_dcoor			camsp;
	t_dcoor			trans;
	t_coor			start;
	t_coor			end;
	int				spscreen;
	int				sph;
	int				spw;
	t_coor			texsp;
	double			*distwall;
}					t_spr;

typedef struct		s_mlx
{
	void			*ptr;
	void			*winptr;
	void			*imgptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				w;
	int				h;
	int				color;
}					t_mlx;

typedef	struct		s_sprites
{
	t_dcoor			coor;
	double			dist;
	int				ordre;
	t_mlx			img;
}					t_sprites;

typedef	struct		s_tex
{
	double			resize;
}					t_tex;

typedef	struct		s_ind
{
	int				j;
	int				i;
	int				a;
	int				b;
}					t_ind;

typedef	struct		s_inv
{
	int				k;
	int				j;
	int				i;
	int				a;
}					t_inv;

typedef struct		s_bmp
{
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

typedef	struct		s_all
{
	t_color			color;
	t_resolution	resolution;
	t_image			image;
	t_texture		texture;
	t_tex			*tex;
	t_mouv			mouv;
	t_raycast		raycast;
	t_spr			spr;
	t_sprites		*sprites;
	t_mlx			mlx;
	t_ind			ind;
	t_inv			m;
}					t_all;

void				ft_open(char *av, t_all *data);
void				initall(t_all *data);
void				convert_lst_to_char(t_all *data, t_list *lst);
char				*del_space_str(char *str);
void				ft_delete_space(char *buff, int *i);
void				ft_print_my_struct(t_all *data);
void				ft_fill_my_struct(char *buff, t_all *data, t_list **lst);
void				ft_fill_resolution(char *buff, int i, t_all *data);
void				ft_fill_color(t_all *data, char *buff, int i, int *color);
void				ft_fill_map(char *buff, t_list **lst, t_all *data);
void				ft_fill_texture(char *buff, int i, t_all *data, char c);
void				ft_raycasting(t_all *data);
int					ft_bouge(t_all *data);
int					ft_depush(int key, t_all *data);
int					ft_push(int key, t_all *data);
int					*ft_print_image(t_all *data);
void				get_texture_all(t_all *data);
void				get_texture_we(t_all *data);
void				get_texture_ea(t_all *data);
void				get_texture_so(t_all *data);
void				get_texture_no(t_all *data);
void				ft_sprites(t_all *data);
void				draw_pix(t_all *data, int x, int y);
void				draw_sprites(t_all *data, int x, int i);
void				color_dist(t_all *data, double dis);
void				sprite_dimensions(t_all *data);
void				get_color(t_all *all, int i);
void				sprite_position(t_all *data, int i);
void				ft_order_sprite(t_all *data);
void				sort_sprites(t_all *data);
void				calc_gap(int *gap);
double				ft_power(double nb, int power);
void				ft_swap_dbl(double *a, double *b);
void				ft_swap_int(int *a, int *b);
void				init_sprites(t_all *all);
void				ft_raycast_nine(t_all *data);
void				ft_raycast_height(t_all *data);
void				ft_raycast_seven(t_all *data);
void				ft_raycast_six(t_all *data);
void				ft_raycast_five(t_all *data);
void				ft_raycast_four(t_all *data);
void				ft_raycast_three(t_all *data);
void				ft_raycast_two(t_all *data);
void				sp_dimension(t_all *all);
void				sp_position(t_all *all, int i);
void				ft_sort_sp(t_all *all);
void				ft_sort(t_all *all);
float				ft_fpower(float nb, int power);
void				ft_bouge_four(t_all *data);
void				ft_bouge_thee(t_all *data);
void				ft_bouge_two(t_all *data);
t_mlx				get_texture_sprite(t_all *all);
void				ft_error(t_all *data);
void				ft_position_error2(t_all *data);
void				ft_position_error4(t_all *data);
void				ft_position_error3(t_all *data, int j, int i);
void				ft_position(t_all *data);
void				ft_position_error1(t_all *data);
void				ft_position_error_text(t_all *data);
void				ft_position_bis_error(t_all *data);
void				error_color(void);
void				error_map(void);
void				error_texture(void);
void				error_resolution(void);
void				fichier_vide_and_reso_haute(t_all *data);
void				ft_error_color_bis(char *buff);
void				set_header(unsigned char *header, int param);
void				imgbmp(t_all *all, t_bmp *bmp);
void				ft_header(t_all *all, t_bmp *bmp);
void				ft_bmp(t_all *all);
void				ft_map_error_bis(t_all *data);
void				check_diff(t_all *data, int i, int j, int diff);
void				ft_reso_bis(t_all *data);
void				ft_verif(t_all *data);
void				ft_exit(t_all *all);
void				check_ac(int ac);
void				error_arg(void);
int					ft_croix(t_all *data);
void				ft_bmpinit(t_all *all);
int					ft_cub(char *argv);

#endif
