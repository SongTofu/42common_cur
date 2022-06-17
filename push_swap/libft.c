/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:09:29 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 13:26:25 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_exit(char *s)
{
	const int	len = ft_strlen(s);

	write(1, s, len);
	exit(0);
}

int				ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long long		ft_atoi(char **s, int sign)
{
	long long	ret;

	ret = 0;
	while (ft_isdigit(**s))
	{
		ret = ret * 10 + **s - '0';
		(*s)++;
	}
	ret *= sign;
	if (!(ret <= INT_MAX && ret >= INT_MIN))
		ft_exit("ERROR\n");
	return (ret);
}

void			ft_memset(char *dest, int size, char ch)
{
	while (size--)
		*(dest++) = ch;
}

void			*ft_calloc(size_t number, size_t size, char ch)
{
	void		*ret;
	size_t		idx;

	idx = 0;
	ret = (char *)malloc(size * number);
	if (!ret)
		ft_exit("ERROR\n");
	ft_memset(ret, size * number, ch);
	return (ret);
}
