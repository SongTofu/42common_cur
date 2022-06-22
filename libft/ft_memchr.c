/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:20:58 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:29 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*ubuf;
	unsigned char	uc;

	ubuf = (unsigned char *)buf;
	uc = (unsigned char)c;
	while (count--)
	{
		if (*(ubuf) == uc)
			return (ubuf);
		ubuf++;
	}
	return (NULL);
}
