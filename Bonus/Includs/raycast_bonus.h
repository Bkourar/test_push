/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:29:02 by bikourar          #+#    #+#             */
/*   Updated: 2025/03/13 23:49:50 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
#define RAYCAST_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>

# define WIDTH 1920
# define HIGHT 1080
# define TZ 64
# define FOV 60
# define NOT 1198542079

typedef enum s_maping
{
	NORTH,				//up
	SOUTH,				//down
	WEST,				//left
	EAST				//right
}	t_maping;

typedef struct	s_crd
{
	double	x;
	double	y;
}			t_crd;

typedef struct	plyer
{
	double		rot;	//player angle
	t_crd		p;		//coordinate player
}				t_ply;

typedef struct	rays
{
	double		rot;	//ray angle
	double		ds;		//ray distance with wall
	bool		sens;	//projections
	t_crd	r;
}			t_rys;

typedef struct s_txt
{
	uint32_t		cillen;
	uint32_t		floor;
	mlx_texture_t	*text_n;
	mlx_texture_t	*text_s;
	mlx_texture_t	*text_w;
	mlx_texture_t	*text_e;
	mlx_texture_t	*frame1;
	mlx_texture_t	*frame2;
	t_maping		*maping;
	t_crd			c;
}					t_txt;

typedef struct	s_information
{
	int				w_w;		//width
	int				h_h;		//highet
	char			**plan;		//map input
	mlx_t			*mlx;
	mlx_image_t		*im;		//images
	int				wid;
	mlx_texture_t	*text;		// texture loading
	mlx_texture_t	*t_sprit;		// texture loading
	t_txt			load_i;		//texture paramter
	t_ply			pl;			//player paramter
	t_rys			ra[WIDTH];	//rays array
	bool			sprit_on;	//action active
}					t_inf;

void			run(void *arg);
double			deg2rad(double deg);
double			rad2deg(double rad);
void			raycasting(t_inf *s);
double			norm_rays(double ang);
void			rendering(void *arg);
int				checking(double x, double y, t_inf *s);
void			set_distance(t_rys *r, t_crd h, t_crd v, t_ply c);
t_maping		gtd_hor(double ang);
t_maping		gtd_ver(double ang);
mlx_texture_t	*get_texture(t_inf *s, int i);
bool			right(t_inf *s);
bool			left(t_inf *s);
bool			down(t_inf *s);
bool			up(t_inf *s);
uint32_t		get_color(uint32_t color);
mlx_texture_t	*get_frame(t_inf *s);

#endif