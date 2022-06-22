/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 04:40:06 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/08 01:27:53 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	long	ret;
	int		len;

	s = (char *)str;
	sign = 1;
	len = ft_strlen(s);
	ret = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32 || *s == '0')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + *s - 48;
		s++;
	}
	return (ret * sign);
}
