/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:02:04 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 12:46:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int				ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void			lower(char **line)
{
	const int	l_len = ft_strlen(*line);
	int			i;
	char		*l;

	i = -1;
	l = *line;
	while (++i < l_len)
	{
		if (l[i] >= 'A' && l[i] <= 'Z')
			l[i] += 32;
	}
}

void			ft_free(t_list **a, t_list **b)
{
	t_list		*cur;
	t_list		*t;

	cur = *a;
	while (cur)
	{
		t = cur->next;
		free(cur);
		cur = t;
	}
	cur = *b;
	while (cur)
	{
		t = cur->next;
		free(cur);
		cur = t;
	}
}
