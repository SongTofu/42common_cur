/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:52:07 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/11 22:47:35 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned char	*b;
	unsigned char	*l;
	size_t			len;

	b = (unsigned char *)big;
	l = (unsigned char *)little;
	len = ft_strlen(little);
	if (!*(char *)little)
		return ((char *)b);
	while (n && *b && *l)
	{
		if (n < len)
			return (0);
		if (ft_strncmp((const char *)b, (const char *)l, len) == 0)
			return ((char *)b);
		b++;
		n--;
	}
	return (0);
}
