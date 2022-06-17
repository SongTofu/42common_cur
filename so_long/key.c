/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:14:54 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 16:44:19 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_finish(t_game *g)
{
	if (g->b.c_count == g->finish)
	{
		printf("walk :: %d\n", ++g->walk);
		good_bye(g, "SUCCESS!\n");
	}
	else
		printf("EAT THE COLLECT\n");
}

void	eat_collect(t_game *g, int x, int y)
{
	t_lst	*cur;

	g->finish++;
	cur = g->b.collect;
	while (cur)
	{
		if (cur->p.x == x && cur->p.y == y)
			cur->eat = 1;
		cur = cur->n;
	}
}

void	move(t_game *g, int i, int j)
{
	int	x;
	int	y;

	x = g->b.player.x + i;
	y = g->b.player.y + j;
	if (g->b.map[y][x] != '1')
	{
		if (g->b.map[y][x] == 'E')
			is_finish(g);
		if (g->b.map[y][x] == 'C')
			eat_collect(g, x, y);
		if (!(g->b.map[y][x] == 'E' && g->b.c_count != 0))
		{
			g->b.map[y][x] = '0';
			g->b.map[y][x] = 'P';
			g->b.player.x = x;
			g->b.player.y = y;
			printf("walk :: %d\n", ++g->walk);
		}
	}
}

int	key_press(int key, t_game *g)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		move(g, 0, -1);
	else if (key == K_A)
		move(g, -1, 0);
	else if (key == K_S)
		move(g, 0, 1);
	else if (key == K_D)
		move(g, 1, 0);
	return (0);
}

int	close_mouse(void)
{
	exit(0);
}
