/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:21:53 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 16:39:31 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *s)
{
	const int	len = ft_strlen(s);

	write(1, s, len);
	exit(0);
}

void	ft_free(char **line)
{
	if (*line)
		free(*line);
	*line = 0;
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	*ft_calloc(size_t number, size_t size, char ch)
{
	void	*ret;
	size_t	idx;

	idx = 0;
	ret = (char *)malloc(size * number);
	if (!ret)
		ft_exit("ERROR memory alloc failed");
	ft_memset(ret, size * number, ch);
	return (ret);
}
