/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:13:15 by song-yejin        #+#    #+#             */
/*   Updated: 2021/10/20 16:32:59 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ending(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
		pthread_mutex_destroy(&info->ph[i].lock);
	}
	pthread_mutex_destroy(&info->status);
	free(info->ph);
	free(info->fork);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (fill_info(ac, av, &info))
		return (RET_ERROR);
	if (set_ph(&info))
		return (RET_ERROR);
	if (init(&info))
		return (RET_ERROR);
	ending(&info);
	return (RET_SUCCESS);
}
