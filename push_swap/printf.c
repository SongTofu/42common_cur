/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:38:29 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 12:46:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf(char *s)
{
	write(1, s, ft_strlen(s));
}

void	oper_printf(t_info mv)
{
	oper_printf2(mv.same_rotate, "rr\n");
	oper_printf2(mv.a_rotate, "ra\n");
	oper_printf2(mv.b_rotate, "rb\n");
}

void	oper_printf2(long long t, char *c)
{
	while (t > 0)
	{
		--t;
		ft_printf(c);
	}
	while (t < 0)
	{
		++t;
		write(1, "r", 1);
		ft_printf(c);
	}
}
