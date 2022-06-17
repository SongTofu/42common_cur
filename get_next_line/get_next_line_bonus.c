/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yjsong0502@daum.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:54:08 by yejsong           #+#    #+#             */
/*   Updated: 2021/01/22 22:54:11 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static char		*buf[OPEN_MAX];
	int				sz;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX <= fd || !line)
		return (RET_ERROR);
	if (!*(buf + fd) && !(*(buf + fd) = ft_calloc(BUFFER_SIZE + 1, 1)))
		return (RET_ERROR);
	*line = 0;
	if (ft_strappend(line, *(buf + fd)))
		return (RET_SUCCESS);
	while ((sz = read(fd, *(buf + fd), BUFFER_SIZE)) > 0)
	{
		*(*(buf + fd) + sz) = 0;
		if (ft_strappend(line, *(buf + fd)))
			return (RET_SUCCESS);
	}
	if (sz < 0)
		ft_free(line);
	ft_free(buf + fd);
	return (sz < 0 ? RET_ERROR : RET_EOF);
}
