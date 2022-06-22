/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:11:01 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/12 01:02:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*cur;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (0);
	tmp = lst->next;
	cur = new;
	while (tmp)
	{
		if (!(cur->next = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		cur = cur->next;
		tmp = tmp->next;
	}
	return (new);
}
