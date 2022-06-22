/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:13:02 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:34 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char *t_dest;
	unsigned char *t_src;

	if (dest == 0 && src == 0)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	while (count--)
	{
		*(t_dest++) = *(t_src++);
	}
	return (dest);
}
