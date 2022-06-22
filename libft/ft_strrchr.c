/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:30:56 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:54:01 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	i = 1;
	s = (char *)str;
	while (*s)
	{
		s++;
		i++;
	}
	if (*s == c)
		return (s);
	while (i--)
	{
		if (*s == c)
			return (s);
		s--;
	}
	return (NULL);
}
