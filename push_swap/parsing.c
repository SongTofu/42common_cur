/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:50:36 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 15:10:30 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ag_parsing(t_list **lst, char *ag, int sz)
{
	char	*it;
	int		sign;

	it = ag;
	while (it && *it)
	{
		sign = 0;
		while (*it == ' ')
			it++;
		if (*it == '-' || *it == '+')
		{
			sign = *it == '-' ? -1 : 1;
			it++;
		}
		if (*it && ft_isdigit(*it))
			sz += make_node(ft_atoi(&it, sign ? sign : 1), lst);
		else if (sign && (*it == ' ' || *it == '\0'))
			ft_exit("ERROR\n");
		if (!(*it == ' ' || *it == '\0'))
			ft_exit("ERROR\n");
	}
	return (sz);
}

int			ags_get(int ac, char *ag[], t_list **lst)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (++i < ac)
		ret += ag_parsing(lst, ag[i], 0);
	return (ret);
}

int			make_node(int idx, t_list **lst)
{
	t_list	*t;
	t_list	*cur;

	cur = *lst;
	t = (t_list *)ft_calloc(1, sizeof(t_list), 0);
	t->n = idx;
	if (!cur)
		*lst = t;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = t;
	}
	return (1);
}

void		dup_ck(t_list *lst_a)
{
	t_list	*iter_a;
	t_list	*iter_b;

	iter_a = lst_a;
	while (iter_a)
	{
		iter_b = iter_a->next;
		while (iter_b)
		{
			if (iter_a->n == iter_b->n)
				ft_exit("ERROR\n");
			iter_b = iter_b->next;
		}
		iter_a = iter_a->next;
	}
}
