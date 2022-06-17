/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:36:12 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 16:44:04 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	good_bye(t_game *g, char *s)
{
	int	i;

	lst_clear(g->b.collect);
	lst_clear(g->b.exit);
	i = -1;
	while (++i < 5)
		mlx_destroy_image(g->mlx, g->img[i].ptr);
	mlx_destroy_image(g->mlx, g->monitor.ptr);
	mlx_destroy_window(g->mlx, g->win);
	ft_exit(s);
}

void	texture_init(t_game *g)
{
	int	i;

	g->img[0].ptr = mlx_xpm_file_to_image(g->mlx, \
	"./texture/grass.xpm", &g->img[0].w, &g->img[0].h);
	g->img[1].ptr = mlx_xpm_file_to_image(g->mlx, \
	"./texture/wall.xpm", &g->img[1].w, &g->img[1].h);
	g->img[2].ptr = mlx_xpm_file_to_image(g->mlx, \
	"./texture/ball.xpm", &g->img[2].w, &g->img[2].h);
	g->img[3].ptr = mlx_xpm_file_to_image(g->mlx, \
	"./texture/exit.xpm", &g->img[3].w, &g->img[3].h);
	g->img[4].ptr = mlx_xpm_file_to_image(g->mlx, \
	"./texture/fro_l.xpm", &g->img[4].w, &g->img[4].h);
	i = -1;
	while (++i < 5)
	{
		if (g->img[i].ptr == NULL)
			ft_exit("ERROR :: XPM to image Fail!\n");
		g->img[i].data = (int *)mlx_get_data_addr(g->img[i].ptr, \
		&g->img[i].bpp, &g->img[i].size_l, &g->img[i].endian);
	}
}

int	main(int ac, char **av)
{
	t_game	g;

	av_ck(ac, av);
	ft_memset((char *)&g, sizeof(t_game), 0);
	g.mlx = mlx_init();
	file_read(av[1], &g.b);
	texture_init(&g);
	g.monitor.ptr = mlx_new_image(g.mlx, \
	g.b.width * TILE_SIZE, g.b.height * TILE_SIZE);
	g.monitor.data = (int *)mlx_get_data_addr(g.monitor.ptr, \
	&g.monitor.bpp, &g.monitor.size_l, &g.monitor.endian);
	g.win = mlx_new_window(g.mlx, g.b.width * TILE_SIZE, \
	g.b.height * TILE_SIZE, "so_long");
	mlx_loop_hook(g.mlx, &main_loop, &g);
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &key_press, &g);
	mlx_hook(g.win, X_EVENT_EXIT, 0, &close_mouse, &g);
	mlx_loop(g.mlx);
	return (0);
}
