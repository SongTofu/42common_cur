/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:52:13 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 16:42:05 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(t_game *g)
{
	draw_map(g);
	draw_etc(g);
	return (0);
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < g->b.height)
	{
		x = -1;
		while (++x < g->b.width)
		{
			if (g->b.map[y][x] == '1')
				draw(g, x, y, g->img[1]);
			else
				draw(g, x, y, g->img[0]);
		}
	}
}

void	draw_etc(t_game *g)
{
	t_lst	*cur;

	cur = g->b.collect;
	while (cur)
	{
		if (!cur->eat)
			draw(g, cur->p.x, cur->p.y, g->img[2]);
		cur = cur->n;
	}
	cur = g->b.exit;
	while (cur)
	{
		draw(g, cur->p.x, cur->p.y, g->img[3]);
		cur = cur->n;
	}
	draw(g, g->b.player.x, g->b.player.y, g->img[4]);
}

void	draw(t_game *g, int x, int y, t_img tex)
{
	mlx_put_image_to_window(g->mlx, g->win, tex.ptr, \
	x * TILE_SIZE, y * TILE_SIZE);
}
