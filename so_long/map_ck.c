/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:50:40 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 17:07:02 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_valid(t_ber *ber)
{
	contents_ck(ber);
	map_rec_ck(ber);
	map_closed_ck(ber);
	return (RET_SUCCESS);
}

void	contents_ck(t_ber *ber)
{
	t_pos	here;

	here.y = -1;
	while (++here.y < ber->height)
	{
		here.x = -1;
		while (++here.x < ber->width)
		{
			if (!ft_strchr("01CEP", ber->map[here.y][here.x]))
				ft_exit("ERROR: CHECK FILE CONTENTS\n");
			if (ber->map[here.y][here.x] == 'C')
				lst_add_back(&(ber->collect), lst_new(here.x, here.y));
			else if (ber->map[here.y][here.x] == 'E')
				lst_add_back(&(ber->exit), lst_new(here.x, here.y));
			num_ck(ber->map[here.y][here.x], 'P', ber, here);
			num_ck(ber->map[here.y][here.x], 'E', ber, here);
			num_ck(ber->map[here.y][here.x], 'C', ber, here);
		}
	}
	if (ber->p_count <= 0 || ber->c_count <= 0 || \
	ber->e_count <= 0)
		ft_exit("ERROR: CHECK FILE CONTENTS\n");
}

void	num_ck(char c, char flag, t_ber *ber, t_pos here)
{
	if (c == flag && flag == 'P')
	{
		ber->player.x = here.x;
		ber->player.y = here.y;
		ber->p_count++;
		if (ber->p_count != 1)
			ft_exit("ERROR: CHECK FILE CONTENTS\n");
	}
	else if (c == flag && flag == 'E')
		ber->e_count++;
	else if (c == flag && flag == 'C')
		ber->c_count++;
}

void	map_rec_ck(t_ber *ber)
{
	size_t	t;
	size_t	len;
	int		i;

	t = ft_strlen(ber->map[0]);
	i = 0;
	while (++i < ber->height)
	{
		len = ft_strlen(ber->map[i]);
		if (t != len)
			ft_exit("ERROR :: MAP NON Rectangle\n");
	}
}

void	map_closed_ck(t_ber *ber)
{
	int	i;

	i = -1;
	while (++i < ber->height)
	{
		if (ber->map[i][0] != '1')
			ft_exit("ERROR :: MAP NON CLOSED\n");
		if (ber->map[i][ber->width - 1] != '1')
			ft_exit("ERROR :: MAP NON CLOSED\n");
	}
	i = -1;
	while (++i < ber->width)
	{
		if (ber->map[0][i] != '1')
			ft_exit("ERROR :: MAP NON CLOSED\n");
		if (ber->map[ber->height - 1][i] != '1')
			ft_exit("ERROR :: MAP NON CLOSED\n");
	}
}
