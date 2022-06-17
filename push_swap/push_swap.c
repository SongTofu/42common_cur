/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:55:42 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 15:06:14 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_init(t_tmp *t, t_list **a, t_list **b)
{
	*a = 0;
	*b = 0;
	ft_memset((char *)t, sizeof(t_tmp), 0);
	t->b_sz = 1;
}

int			main(int ac, char *ag[])
{
	t_list	*a;
	t_list	*b;
	t_tmp	t;

	push_swap_init(&t, &a, &b);
	t.a_sz = ags_get(ac, ag, &a) - 1;
	if (ac < 2)
		ft_exit("ERROR\n");
	dup_ck(a);
	ft_push(&b, &a, 'b');
	lst_analysis(&t, &a, &b);
	b_sort(&b, t.b_sz);
	while (t.b_sz > 0)
	{
		ft_push(&a, &b, 'a');
		t.a_sz++;
		t.b_sz--;
	}
	ft_free(&a, &b);
}
