/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:25:40 by yejsong           #+#    #+#             */
/*   Updated: 2021/05/25 14:26:46 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(int *order, double *dist, int n)
{
	t_pair	*s;
	int		i;

	s = (t_pair *)malloc(sizeof(t_pair) * n);
	i = -1;
	while (++i < n)
	{
		s[i].first = dist[i];
		s[i].second = order[i];
	}
	sort_order(s, n);
	i = -1;
	while (++i < n)
	{
		dist[i] = s[n - i - 1].first;
		order[i] = s[n - i - 1].second;
	}
	free(s);
}

void	sort_order(t_pair *o, int n)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - 1)
		{
			if (o[j].first > o[j + 1].first)
			{
				tmp.first = o[j].first;
				tmp.second = o[j].second;
				o[j].first = o[j + 1].first;
				o[j].second = o[j + 1].second;
				o[j + 1].first = tmp.first;
				o[j + 1].second = tmp.second;
			}
		}
	}
}
