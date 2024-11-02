/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:20:52 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/02 18:41:22 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void draw_opened_door(t_exec *exec, int *color, t_ray *ray, float angle)
{
	int	prev;
	char up;
	char right;

	it_is_up_or_down(exec->ply.rotangle, &up);
	it_is_left_or_right(exec->ply.rotangle, &right);
	prev = *color;
	if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2)
			|| (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
	{
		if (exec->info.old_map[(int)floor((ray->dy - 1) / PIXELS)][(int)floor((ray->dx) / PIXELS)] == 'D')
		{
			// if (up)
				*color = get_pixel(exec->odlr->pixels, ray->o);
			// else if (printf("h\n"))
			// 	*color = get_pixel(exec->odrl->pixels, ray->o);
		}
	}
	else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
	{
		if (exec->info.old_map[(int)floor(ray->dy / PIXELS)][(int)floor((ray->dx - 1) / PIXELS)] == 'D')
			*color = get_pixel(exec->odrr->pixels, ray->o);
	}
	else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
	{
		if (exec->info.old_map[(int)floor(ray->dy / PIXELS)][(int)floor((ray->dx - 1) / PIXELS)] == 'D')
		{
			if (up)
				*color = get_pixel(exec->odll->pixels, ray->o);
			else
				*color = get_pixel(exec->odrl->pixels, ray->o);
		}
			
	}
	else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
	{
		if (exec->info.old_map[(int)floor((ray->dy - 1) / PIXELS)][(int)floor((ray->dx) / PIXELS)] == 'D')
		{
			if (up && printf("here\n"))
				*color = get_pixel(exec->odll->pixels, ray->o);
			else
				*color = get_pixel(exec->odrl->pixels, ray->o);

		}
	}
	if (*color == 0)
		*color = prev;
}

static void	set_color_value(t_exec *exec, float angle, int *color, t_ray *ray)
{

	if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2)
			|| (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
		*color = get_pixel(exec->we->pixels, ray->o);
	else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
		*color = get_pixel(exec->ea->pixels, ray->o);
	else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
		*color = get_pixel(exec->so->pixels, ray->o);
	else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
		*color = get_pixel(exec->no->pixels, ray->o);
	draw_opened_door(exec, color, ray, angle);
	if (ray->d == 2)
		*color = get_pixel(exec->d->pixels, ray->o);
}

void	draw_the_textures(t_exec *exec, float angle, int *y, t_ray *ray)
{
	int	ofsetx;
	int	ofsety;
	int	color;
	int	x;
	int	top;

	x = 0;
	if (ray->hv == 1)
		ofsetx = (int)ray->dx % TILE_SIZE;
	else
		ofsetx = (int)ray->dy % TILE_SIZE;
	while ((int)x++ < ray->wall_height && x <= (int)exec->info.win_hei)
	{
		top = *y + (ray->wall_height / 2) - (exec->info.win_hei / 2);
		ofsety = top * ((float)TILE_SIZE / ray->wall_height);
		ray->o = ((TILE_SIZE * ofsety) + ofsetx) * 4;
		if (ray->o >= 0 && ray->o + 3 < (TILE_SIZE * TILE_SIZE * 4))
			set_color_value(exec, angle, &color, ray);
		mlx_put_pixel(exec->wind_image, ray->x, (*y)++, color);
	}
}

int	switch_rgb_hex(int color[3], int a)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | a);
}

int	is_invalid(char **map, int i, size_t j)
{
	return (
		((i == 0 || j == 0) && (map[i][j] != '1')) ||
		(map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == '\0')
		|| ((map[i - 1][j] == ' ' || map[i - 1][j] == '\0')) ||
		(map[i + 1] == NULL
		|| (map[i + 1][j] == ' ' || map[i + 1][j] == '\0')));
}
