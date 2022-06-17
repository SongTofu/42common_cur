/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:41:28 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 12:46:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lst_analysis(t_tmp *t, t_list **a, t_list **b)
{
	t_info	mv;
	t_info	mx;
	t_info	mn;

	while (t->a_sz)
	{
		t->iter_a = *a;
		t->idx_i = -1;
		ft_memset((char *)&mv, sizeof(t_info), 1);
		while (++t->idx_i < t->a_sz)
		{
			run(t, &mn, &mx, b);
			if (mn.tot <= mx.tot && mn.tot < mv.tot)
				mv = mn;
			else if (mx.tot < mv.tot)
				mv = mx;
		}
		move_stack(a, mv.same_rotate + mv.a_rotate);
		move_stack(b, mv.same_rotate + mv.b_rotate);
		oper_printf(mv);
		ft_push(b, a, 'b');
		t->a_sz--;
		t->b_sz++;
	}
}

void		run(t_tmp *t, t_info *mn, t_info *mx, t_list **b)
{
	ft_memset((char *)mx, sizeof(t_info), 1);
	ft_memset((char *)mn, sizeof(t_info), 1);
	mn->num *= -1;
	t->idx_j = -1;
	t->iter_b = *b;
	while (++t->idx_j < t->b_sz)
	{
		if (t->iter_a->n < t->iter_b->n && mx->num > t->iter_b->n)
		{
			mx->num = t->iter_b->n;
			func(t, 1, mx);
		}
		if (t->iter_a->n > t->iter_b->n && mn->num < t->iter_b->n)
		{
			mn->num = t->iter_b->n;
			func(t, 0, mn);
		}
		t->iter_b = t->iter_b->next;
	}
	t->iter_a = t->iter_a->next;
}

void		func(t_tmp *t, int flag, t_info *tmp)
{
	if (flag)
	{
		calc(tmp, t->idx_i, t->idx_j + 1, 0);
		calc(tmp, -(t->a_sz - t->idx_i), -(t->b_sz - t->idx_j - 1), 1);
		calc(tmp, t->idx_i, -(t->b_sz - t->idx_j - 1), 1);
		calc(tmp, -(t->a_sz - t->idx_i), t->idx_j + 1, 1);
	}
	else
	{
		calc(tmp, t->idx_i, t->idx_j, 0);
		calc(tmp, -(t->a_sz - t->idx_i), -(t->b_sz - t->idx_j), 1);
		calc(tmp, t->idx_i, -(t->b_sz - t->idx_j), 1);
		calc(tmp, -(t->a_sz - t->idx_i), t->idx_j, 1);
	}
}

void		calc(t_info *t, int a, int b, int flag)
{
	if (a * b > 0)
	{
		if (flag && t->tot < ft_max(abs(a), abs(b)))
			return ;
		t->same_rotate = abs(a) > abs(b) ? b : a;
		t->a_rotate = a - t->same_rotate;
		t->b_rotate = b - t->same_rotate;
		t->tot = ft_max(abs(a), abs(b));
	}
	else
	{
		if (flag && t->tot < abs(a - b))
			return ;
		t->same_rotate = 0;
		t->a_rotate = a;
		t->b_rotate = b;
		t->tot = abs(a) + abs(b);
	}
}

void		b_sort(t_list **b, int size)
{
	t_list	*cur;
	t_info	mv;
	int		i;

	ft_memset((char *)&mv, sizeof(t_info), 0);
	cur = *b;
	i = 1;
	while (cur)
	{
		if (cur->next && cur->n < cur->next->n)
			break ;
		cur = cur->next;
		i++;
	}
	mv.b_rotate = ft_min(size - i, i);
	if (mv.b_rotate == -1)
		mv.b_rotate = 0;
	if (mv.b_rotate == i)
		move_stack(b, mv.b_rotate);
	else
	{
		move_stack(b, -mv.b_rotate);
		mv.b_rotate *= -1;
	}
	oper_printf(mv);
}
