/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:10:38 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 12:46:58 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				*ft_strchr(const char *str, int c)
{
	char			*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!*s && !c)
		return (s);
	return (NULL);
}

size_t				ft_strlen(char *str)
{
	size_t			len;

	if (!str)
		return (0);
	len = 0;
	while (str && *str)
	{
		str++;
		len++;
	}
	return (len);
}

void				*ft_memcpy(void *dest, const void *src, size_t count)
{
	char			*cpy;

	if (!dest && !src)
		return (0);
	cpy = (char *)dest;
	while (count--)
		*(cpy++) = *(char *)(src++);
	return (dest);
}

int					ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void				ft_append(char **line, char c)
{
	const size_t	l_len = ft_strlen(*line);
	char			*tmp;

	tmp = ft_calloc(l_len + 2, 1, 0);
	ft_memcpy(tmp, *line, l_len);
	*(tmp + l_len) = c;
	if (*line)
		free(*line);
	*line = tmp;
}
