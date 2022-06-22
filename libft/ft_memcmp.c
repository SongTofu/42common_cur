/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:26:55 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:31 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*ubuf1;
	unsigned char	*ubuf2;

	ubuf1 = (unsigned char *)buf1;
	ubuf2 = (unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (count--)
	{
		if (*ubuf1 != *ubuf2)
			return (*ubuf1 - *ubuf2);
		ubuf1++;
		ubuf2++;
	}
	return (0);
}
