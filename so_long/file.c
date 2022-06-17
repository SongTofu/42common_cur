/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:55:00 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 17:06:42 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	av_ck(int ac, char **av)
{
	if (ac != 2)
		ft_exit("ERROR: CHECK PARAMETER\n");
	if (file_cker(av[1], ".ber") == RET_ERROR)
		ft_exit("ERROR: CHECK EXTENSION\n");
}

int	file_cker(char *filename, char *extension)
{
	const int	len = ft_strlen(filename);
	int			i;

	i = -1;
	while (++i < len)
	{
		if (filename[i] >= 'A' && filename[i] <= 'Z')
			filename[i] += 32;
	}
	if (ft_strncmp(extension, filename + len - 4, 4))
		return (RET_ERROR);
	return (RET_SUCCESS);
}

void	file_read(char *filename, t_ber *ber)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit("ERROR: FILE CANNOT BE FOUND\n");
	if (ber_parsing(fd, ber) == RET_ERROR)
		ft_exit("ERROR: CHECK FILE CONTENTS\n");
	if (map_valid(ber) == RET_ERROR)
		ft_exit("ERROR: CHECK FILE CONTENTS\n");
	close(fd);
}

int	ber_parsing(int fd, t_ber *ber)
{
	char	*line;
	int		status;

	line = 0;
	status = 1;
	ber->width = 0;
	while (status > 0)
	{
		status = get_a_line(fd, &line);
		ber->height++;
		ber->width = ft_max(status, ber->width);
		if (status == RET_ERROR)
			return (RET_ERROR);
	}
	make_map(line, ber);
	return (RET_SUCCESS);
}

void	make_map(char *line, t_ber *ber)
{
	char	*start;
	char	*end;
	char	**tmp;
	int		i;

	i = -1;
	end = line;
	start = line;
	tmp = ft_calloc(ber->height, sizeof(char **), 0);
	while (++i < ber->height)
		*(tmp + i) = ft_calloc(ber->width, sizeof(char *), 0);
	i = -1;
	while (line && *end)
	{
		start = end;
		while (*end && *end != '\n')
			end++;
		ft_memcpy(*(tmp + (++i)), start, end - start);
		if (*end)
			end++;
	}
	ber->map = tmp;
	ft_free(&line);
}
