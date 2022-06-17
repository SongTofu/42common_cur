/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:20:36 by song-yejin        #+#    #+#             */
/*   Updated: 2021/05/25 16:03:17 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_casting(t_game *g)
{
	t_scasting	ts;
	int			i;

	ft_memset((char *)&ts, sizeof(t_scasting), 0);
	sprite_init(g);
	i = -1;
	while (++i < g->num_sprite)
	{
		sprite_calc(g, &ts, i);
		draw_sprites(g, &ts, 0);
	}
}

void	sprite_init(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->num_sprite)
	{
		g->sprite_o[i] = i;
		g->sprite_d[i] = ((g->pos_x - g->s[i].x) * (g->pos_x - g->s[i].x) + \
		(g->pos_y - g->s[i].y) * (g->pos_y - g->s[i].y));
	}
	sort_sprites(g->sprite_o, g->sprite_d, g->num_sprite);
}

void	sprite_calc(t_game *g, t_scasting *ts, int i)
{
	ts->sprite_x = g->s[g->sprite_o[i]].x - g->pos_x;
	ts->sprite_y = g->s[g->sprite_o[i]].y - g->pos_y;
	ts->invdet = 1.0 / (g->plane_x * g->dir_y - g->dir_x * g->plane_y);
	ts->transform_x = ts->invdet * \
	(g->dir_y * ts->sprite_x - g->dir_x * ts->sprite_y);
	ts->transform_y = ts->invdet * \
	(-g->plane_y * ts->sprite_x + g->plane_x * ts->sprite_y);
	ts->spritescreen_x = (int)((g->win_x / 2) * \
	(1 + ts->transform_x / ts->transform_y));
	ts->sprite_h = (int)fabs(g->win_y / ts->transform_y);
	ts->draw_s_y = -ts->sprite_h / 2 + g->win_y / 2;
	if (ts->draw_s_y < 0)
		ts->draw_s_y = 0;
	ts->draw_e_y = ts->sprite_h / 2 + g->win_y / 2;
	if (ts->draw_e_y >= g->win_y)
		ts->draw_e_y = g->win_y - 1;
	ts->sprite_w = (int)fabs(g->win_y / ts->transform_y);
	ts->draw_s_x = -ts->sprite_w / 2 + ts->spritescreen_x;
	if (ts->draw_s_x < 0)
		ts->draw_s_x = 0;
	ts->draw_e_x = ts->sprite_w / 2 + ts->spritescreen_x;
	if (ts->draw_e_x >= g->win_x)
		ts->draw_e_x = g->win_x - 1;
}

void	draw_sprites(t_game *g, t_scasting *ts, int color)
{
	int	stripe;
	int	y;
	int tex_x;
	int	d;
	int	tex_y;

	stripe = ts->draw_s_x - 1;
	while (++stripe < ts->draw_e_x)
	{
		tex_x = (int)((256 * (stripe - (-ts->sprite_w / 2 + \
		ts->spritescreen_x)) * (int)g->sz_img[4].x / ts->sprite_w) / 256);
		if (ts->transform_y > 0 && stripe > 0 && \
		stripe < g->win_x && ts->transform_y < g->z_buffer[stripe])
		{
			y = ts->draw_s_y - 1;
			while (++y < ts->draw_e_y)
			{
				d = y * 256 - g->win_y * 128 + ts->sprite_h * 128;
				tex_y = ((d * (int)g->sz_img[4].y) / ts->sprite_h) / 256;
				color = g->texture[4][(int)g->sz_img[4].x * tex_y + tex_x];
				if ((color & 0x00FFFFFF) != 0)
					g->buf[y][stripe] = color;
			}
		}
	}
}
