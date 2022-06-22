/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:13:48 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/10 00:40:26 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;

	if (!s1 || !set)
		return (0);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		++s1;
	}
	start = (char *)s1;
	end = (char *)s1;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			end = (char *)s1;
		++s1;
	}
	if (!(ret = ft_calloc(end - start + 2, 1)))
		return (0);
	ft_strlcpy(ret, start, end - start + 2);
	return (ret);
}
