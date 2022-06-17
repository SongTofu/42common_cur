/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:35:40 by song-yejin        #+#    #+#             */
/*   Updated: 2021/10/30 22:49:07 by song-yejin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lst	*lst_new(int x, int y)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->eat = 0;
	new->p.x = x;
	new->p.y = y;
	new->n = NULL;
	return (new);
}

t_lst	*lst_last(t_lst *lst)
{
	t_lst	*curr;

	curr = lst;
	if (lst == NULL)
		return (NULL);
	while (curr->n != NULL)
		curr = curr->n;
	return (curr);
}

void	lst_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lst_last(*lst);
	new->n = last->n;
	last->n = new;
}

void	lst_clear(t_lst *head)
{
	t_lst	*curr;
	t_lst	*next;

	curr = head;
	while (curr != NULL)
	{
		next = curr->n;
		free(curr);
		curr = next;
	}
	head = NULL;
}
