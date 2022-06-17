/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:54 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 12:46:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		move_stack(t_list **lst, int move)
{
	while (move > 0)
	{
		--move;
		ft_rotate(lst);
	}
	while (move < 0)
	{
		move++;
		ft_r_rotate(lst);
	}
}

int			ft_swap(t_list **lst)
{
	t_list	*cur;
	int		t;

	cur = *lst;
	if (cur && cur->next)
	{
		t = cur->n;
		cur->n = cur->next->n;
		cur->next->n = t;
		return (RET_SUCCESS);
	}
	else
		return (RET_ERROR);
}

int			ft_push(t_list **dest, t_list **src, char c)
{
	t_list	*tmp;

	if (!*src)
		return (RET_ERROR);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
	return (RET_SUCCESS);
}

int			ft_rotate(t_list **lst)
{
	t_list	*cur;
	t_list	*t;

	cur = *lst;
	if (cur && cur->next)
	{
		t = cur;
		cur = cur->next;
		*lst = cur;
		while (cur->next)
			cur = cur->next;
		cur->next = t;
		t->next = 0;
		return (RET_SUCCESS);
	}
	else
		return (RET_ERROR);
}

int			ft_r_rotate(t_list **lst)
{
	t_list	*cur;
	t_list	*t;

	cur = *lst;
	if (cur && cur->next)
	{
		while (cur->next->next)
			cur = cur->next;
		t = cur->next;
		cur->next = 0;
		cur = *lst;
		t->next = cur;
		*lst = t;
		return (RET_SUCCESS);
	}
	else
		return (RET_ERROR);
}
