/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:06:42 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 16:57:57 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_append(char **line, char ch)
{
	const size_t	l_len = ft_strlen(*line);
	char			*tmp;
	int				ret;

	tmp = ft_calloc(l_len + 2, 1, 0);
	ret = ch;
	ft_memcpy(tmp, *line, l_len);
	*(tmp + l_len) = ch;
	if (*line)
		free(*line);
	*line = tmp;
	if (ret == '\n')
		return (RET_SUCCESS);
	return (0);
}

int	get_a_line(int fd, char **line)
{
	static char	ch;
	int			sz;
	int			width;

	width = 0;
	if (fd < 0 || !line)
		return (RET_ERROR);
	sz = read(fd, &ch, 1);
	while (sz > 0)
	{
		if (ft_append(line, ch))
			return (width);
		sz = read(fd, &ch, 1);
		width++;
	}
	if (sz == 0)
		return (RET_EOF);
	return (RET_ERROR);
}
