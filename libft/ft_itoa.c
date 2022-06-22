/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 04:14:49 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/11 01:45:04 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		idx;
	long	ln;
	char	*ret;

	idx = n < 1 ? 1 : 0;
	ln = n < 0 ? -(long)n : (long)n;
	while (ln != 0)
	{
		ln = ln / 10;
		idx++;
	}
	if (!(ret = ft_calloc(idx + 1, 1)))
		return (0);
	ln = n < 0 ? -(long)n : (long)n;
	while (idx > 0)
	{
		*(ret + idx - 1) = ln % 10 + '0';
		ln = ln / 10;
		idx--;
	}
	if (n == 0)
		*ret = '0';
	else if (n < 0)
		*ret = '-';
	return (ret);
}
