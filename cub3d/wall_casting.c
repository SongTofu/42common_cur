/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:04:43 by song-yejin        #+#    #+#             */
/*   Updated: 2021/05/25 16:03:17 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_casting(t_game *g)
{
	int			x;
	t_wcasting	tw;

	ft_memset((char *)&tw, sizeof(t_wcasting), 0);
	x = -1;
	while (++x < g->win_x)
	{
		wall_init(x, g, &tw);
		dda(g, &tw);
		get_height(g, &tw);
		draw_one_line(x, g, &tw);
	}
}

void	wall_init(int x, t_game *g, t_wcasting *tw)
{
	tw->camera_x = 2 * x / (double)g->win_x - 1;
	tw->raydir_x = g->dir_x + g->plane_x * tw->camera_x;
	tw->raydir_y = g->dir_y + g->plane_y * tw->camera_x;
	tw->map_x = (int)g->pos_x;
	tw->map_y = (int)g->pos_y;
	tw->deltadist_x = fabs(1 / tw->raydir_x);
	tw->deltadist_y = fabs(1 / tw->raydir_y);
	tw->step_x = 1;
	tw->sidedist_x = (tw->map_x + 1.0 - g->pos_x) * tw->deltadist_x;
	tw->step_y = 1;
	tw->sidedist_y = (tw->map_y + 1.0 - g->pos_y) * tw->deltadist_y;
	if (tw->raydir_x < 0)
	{
		tw->step_x = -1;
		tw->sidedist_x = (g->pos_x - tw->map_x) * tw->deltadist_x;
	}
	if (tw->raydir_y < 0)
	{
		tw->step_y = -1;
		tw->sidedist_y = (g->pos_y - tw->map_y) * tw->deltadist_y;
	}
}

void	dda(t_game *g, t_wcasting *tw)
{
	tw->hit = 0;
	tw->side = 0;
	while (g->map[tw->map_x][tw->map_y] != 1)
	{
		if (tw->sidedist_x < tw->sidedist_y)
		{
			tw->sidedist_x += tw->deltadist_x;
			tw->map_x += tw->step_x;
			tw->side = 0;
		}
		else
		{
			tw->sidedist_y += tw->deltadist_y;
			tw->map_y += tw->step_y;
			tw->side = 1;
		}
	}
	tw->tex_num = 1;
	if (tw->side == 0 && tw->step_x < 0)
		tw->tex_num = 0;
	else if (tw->side == 1 && tw->step_y > 0)
		tw->tex_num = 3;
	else if (tw->side == 1 && tw->step_y < 0)
		tw->tex_num = 2;
}

void	get_height(t_game *g, t_wcasting *tw)
{
	if (tw->side == 0)
		tw->perpwalldist = (tw->map_x - g->pos_x + (1 - \
		tw->step_x) / 2) / tw->raydir_x;
	else
		tw->perpwalldist = (tw->map_y - g->pos_y + (1 - \
		tw->step_y) / 2) / tw->raydir_y;
	tw->line_height = (int)(g->win_y / tw->perpwalldist);
	tw->draw_s = -tw->line_height / 2 + g->win_y / 2;
	if (tw->draw_s < 0)
		tw->draw_s = 0;
	tw->draw_e = tw->line_height / 2 + g->win_y / 2;
	if (tw->draw_e >= g->win_y)
		tw->draw_e = g->win_y - 1;
	if (tw->side == 0)
		tw->wall_x = g->pos_y + tw->perpwalldist * tw->raydir_y;
	else
		tw->wall_x = g->pos_x + tw->perpwalldist * tw->raydir_x;
	tw->wall_x -= floor(tw->wall_x);
	tw->tex_x = (int)(tw->wall_x * \
	(double)g->sz_img[tw->tex_num].x);
	if ((tw->side == 0 && tw->raydir_x > 0) || \
	(tw->side == 1 && tw->raydir_y < 0))
		tw->tex_x = g->sz_img[tw->tex_num].x - tw->tex_x - 1;
	tw->step = 1.0 * g->sz_img[tw->tex_num].y / tw->line_height;
	tw->tex_pos = (tw->draw_s - g->win_y / 2 + tw->line_height / 2) * tw->step;
}

void	draw_one_line(int x, t_game *g, t_wcasting *tw)
{
	int	texx_y;
	int	color;
	int	y;

	y = tw->draw_s - 1;
	while (++y < tw->draw_e)
	{
		texx_y = (int)tw->tex_pos & ((int)g->sz_img[tw->tex_num].y - 1);
		tw->tex_pos += tw->step;
		color = g->texture[tw->tex_num]\
		[(int)g->sz_img[tw->tex_num].y * texx_y + tw->tex_x];
		if (tw->side == 1)
			color = (color >> 1) & 8355711;
		g->buf[y][x] = color;
	}
	g->z_buffer[x] = tw->perpwalldist;
}
