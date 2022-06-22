/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:20:29 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:26 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	i = 0;
	if (dest == src)
		return (NULL);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	cc = (unsigned char)c;
	while (n--)
	{
		*(t_dest) = *(t_src);
		if (*(t_src) == cc)
			return (dest + i + 1);
		t_dest++;
		t_src++;
		i++;
	}
	return (NULL);
}
