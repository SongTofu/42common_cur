/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:41:55 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/05 04:53:39 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dest, int c, size_t count)
{
	unsigned char *tmp;

	tmp = (unsigned char *)dest;
	while (count--)
	{
		*(tmp++) = c;
	}
	return (dest);
}
