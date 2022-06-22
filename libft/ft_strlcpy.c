/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:48:11 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:49 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (0);
	while (i + 1 < n && *src)
	{
		*(dest) = *(src);
		dest++;
		src++;
		i++;
	}
	if (n)
		*dest = '\0';
	while (*src)
	{
		++src;
		++i;
	}
	return (i);
}
