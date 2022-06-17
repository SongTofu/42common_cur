/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:46:33 by song-yejin        #+#    #+#             */
/*   Updated: 2021/05/25 12:44:09 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_update(t_game *g)
{
	if (g->key.w)
	{
		if (!g->map[(int)(g->pos_x + g->dir_x * 0.05)][(int)(g->pos_y)])
			g->pos_x += g->dir_x * 0.05;
		if (!g->map[(int)(g->pos_x)][(int)(g->pos_y + g->dir_y * 0.05)])
			g->pos_y += g->dir_y * 0.05;
	}
	if (g->key.s)
	{
		if (!g->map[(int)(g->pos_x - g->dir_x * 0.05)][(int)(g->pos_y)])
			g->pos_x -= g->dir_x * 0.05;
		if (!g->map[(int)(g->pos_x)][(int)(g->pos_y - g->dir_y * 0.05)])
			g->pos_y -= g->dir_y * 0.05;
	}
	if (g->key.d)
		turn(g, -0.05);
	if (g->key.a)
		turn(g, 0.05);
}

void	turn(t_game *g, double rot)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = g->dir_x;
	g->dir_x = g->dir_x * cos(rot) - g->dir_y * sin(rot);
	g->dir_y = olddir_x * sin(rot) + g->dir_y * cos(rot);
	oldplane_x = g->plane_x;
	g->plane_x = g->plane_x * cos(rot) - g->plane_y * sin(rot);
	g->plane_y = oldplane_x * sin(rot) + g->plane_y * cos(rot);
}

int		key_press(int key, t_game *g)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		g->key.w = 1;
	else if (key == K_A)
		g->key.a = 1;
	else if (key == K_S)
		g->key.s = 1;
	else if (key == K_D)
		g->key.d = 1;
	return (0);
}

int		key_release(int key, t_game *g)
{
	if (key == K_W)
		g->key.w = 0;
	else if (key == K_A)
		g->key.a = 0;
	else if (key == K_S)
		g->key.s = 0;
	else if (key == K_D)
		g->key.d = 0;
	return (0);
}

int		close_mouse(void)
{
	exit(0);
}
