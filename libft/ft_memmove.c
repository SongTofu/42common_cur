/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:48:44 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:37 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	if (dest > src)
		while (count--)
			*(temp + count) = *(unsigned char *)(src + count);
	else
		ft_memcpy(dest, src, count);
	return (dest);
}
