#include "Includs/parse.h"
#include "Includs/raycast.h"

static void	init_parameter(t_inf *mx, t_buff *mem)
{
	mx->mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx->im = mlx_new_image(mx->mlx, WIDTH, HIGHT);
	mlx_image_to_window(mx->mlx, mx->im, 0, 0);
	mx->load_i.text_n = mem->no_tex;
	mx->load_i.text_s = mem->so_tex;
	mx->load_i.text_w = mem->we_tex;
	mx->load_i.text_e = mem->ea_tex;
	mx->load_i.cillen = mem->cell;
	mx->load_i.floor = mem->floo;
	mx->h_h = mem->array_h * TZ;
	mx->w_w = mem->array_w * TZ;
	mx->pl.p.x = (mem->playerx * TZ) + (TZ / 2);
	mx->pl.p.y = (mem->playery * TZ) + (TZ / 2);
	mx->pl.rot = mem->player_deg;
}

static void	destroy_parameter(t_inf mx, t_buff *mem)
{
	(void)mem;
	mlx_terminate(mx.mlx);
	ft_free_mx(&mx);
}

static void	start_game(t_inf mx, t_buff *mem)
{
	(raycasting(&mx), rendering(&mx));
	mlx_loop_hook(mx.mlx, run, &mx);
	mlx_loop_hook(mx.mlx, rendering, &mx);
	mlx_loop(mx.mlx);
	destroy_parameter(mx, mem);
}

void fe()
{
	system("leaks cub3D");
}

int main(int ac, char **av)
{
	atexit(fe);
	t_inf	mx;
	t_buff *mem;

	mem = ft_parsing(ac, av);
	if (!mem)
		return (1);
	if (get_map_mem(&mx, mem))
		return (1);
	get_player_pos(&mx, mem);
	mx.mem = mem;
	init_parameter(&mx, mx.mem);
	start_game(mx, mem);
}
