/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_ck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:34:01 by yejsong           #+#    #+#             */
/*   Updated: 2021/06/30 13:52:46 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		oper_run(t_list **a, t_list **b)
{
	char	c;
	char	*line;

	line = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n' || c == ' ' || c == '\0')
		{
			oper_ck(line, a, b);
			free(line);
			line = 0;
		}
		else
			ft_append(&line, c);
	}
}

void		oper_ck(char *line, t_list **a, t_list **b)
{
	int		ret1;
	int		ret2;

	lower(&line);
	if (!line)
		return ;
	ret1 = oper_ck2(line, a, b);
	ret2 = oper_ck3(line, a, b);
	if (ret1 == RET_ERROR && ret2 == RET_ERROR)
		ft_exit("ERROR\n");
}

int			oper_ck2(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(a);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strcmp(line, "pa"))
		ft_push(a, b, 0);
	else if (!ft_strcmp(line, "pb"))
		ft_push(b, a, 0);
	else
		return (RET_ERROR);
	return (RET_SUCCESS);
}

int			oper_ck3(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "ra"))
		ft_rotate(a);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(b);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_r_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		ft_r_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_r_rotate(a);
		ft_r_rotate(b);
	}
	else
		return (RET_ERROR);
	return (RET_SUCCESS);
}

int			is_sort(t_list **lst)
{
	t_list	*cur;

	cur = *lst;
	while (cur && cur->next)
	{
		if (cur->n > cur->next->n)
			return (RET_ERROR);
		cur = cur->next;
	}
	return (RET_SUCCESS);
}
