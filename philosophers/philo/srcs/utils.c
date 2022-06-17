/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 01:18:47 by song-yejin        #+#    #+#             */
/*   Updated: 2021/10/14 22:01:50 by song-yejin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_exit(char *s)
{
	printf("%s", s);
	return (RET_ERROR);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *s)
{
	long	ret;

	ret = 0;
	while (*s)
	{
		ret = (ret * 10) + (*s - 48);
		s++;
	}
	return (ret);
}

int	real_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == RET_ERROR)
		return (ft_exit("ERROR :: Gettimeofday Return Error\n"));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
