#include "../Includs/raycast.h"

void	rendereding_wall(t_inf *s, int pos_w, double w_hight, int *j)
{
	uint32_t	color;
	int			offex;
	int			offey;
	int			start;

	s->text = get_texture(s, pos_w);
	uint32_t *pexel_arr = (uint32_t *)s->text->pixels;
	if (s->ra[pos_w].sens == true)
		offex = ((s->ra[pos_w].r.x) * s->text->width / TZ);
	else
		offex = ((s->ra[pos_w].r.y) * s->text->width / TZ);
	offex %= s->text->width;
	start = 0;
	while (start < w_hight && *j < HIGHT)
	{
		offey = (*j) - ((HIGHT / 2) - (w_hight / 2));
		offey *= s->text->height / w_hight;
		offey %= s->text->height;
		color = get_color(pexel_arr[s->text->width * offey + offex]);
		mlx_put_pixel(s->im, pos_w, (*j)++, color);
		start++;
	}
	s->text = NULL;
}


static void	rendereding_celling(t_inf *s, int i, double y_h, int *j)
{
	int	celling = (HIGHT / 2) - (y_h / 2);
	while (celling > 0) 
	{
		mlx_put_pixel(s->im, i, (*j), s->load_i.cillen);
		*j = *j + 1;
		celling--;
	}
}

static void	rendereding_floor(t_inf *s, int i,int *j)
{
	while (*j < HIGHT) {
		mlx_put_pixel(s->im, i, (*j), s->load_i.floor);
		*j = *j + 1;
	}
}

void	rendering(void *arg)
{
	t_inf		*s;
	int			i;
	double		cosx;
	double		wall_h;
	int			j;

	cosx = (WIDTH / 2) / tan(deg2rad(FOV / 2));
	s = (t_inf*)arg;
	s->text = NULL;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		wall_h = (TZ / s->ra[i].ds) * cosx;
		rendereding_celling(s, i, wall_h, &j);
		rendereding_wall(s, i, wall_h, &j);
		rendereding_floor(s, i ,&j);
		i++;
	}
}