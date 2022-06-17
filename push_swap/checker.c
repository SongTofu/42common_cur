/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker00                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:44:26 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 15:07:23 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *ag[])
{
	t_list *a;
	t_list *b;

	a = 0;
	b = 0;
	if (ac < 2)
		ft_exit("ERROR\n");
	ags_get(ac, ag, &a);
	dup_ck(a);
	oper_run(&a, &b);
	if (is_sort(&a) == RET_SUCCESS)
		ft_exit("OK\n");
	else
		ft_exit("KO\n");
	ft_free(&a, &b);
}
