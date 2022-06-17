/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:28:41 by yejsong           #+#    #+#             */
/*   Updated: 2021/10/20 16:30:57 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (!ph->info->stop)
	{
		pthread_mutex_lock(&ph->lock);
		if (real_time() - ph->start_time >= ph->info->time_die)
		{
			print_status(ph, DIE);
			ph->info->stop = 1;
			pthread_mutex_unlock(&ph->lock);
			break ;
		}
		pthread_mutex_unlock(&ph->lock);
		usleep(100);
	}
	return (NULL);
}

void	print_status(t_philo *ph, int status)
{
	pthread_mutex_lock(&ph->info->status);
	if (ph->info->stop)
	{
		pthread_mutex_unlock(&ph->info->status);
		return ;
	}
	printf("%d\t Philo %d ", real_time() - ph->info->base_time, ph->n + 1);
	if (status == FORK)
		printf("has taken a fork\n");
	else if (status == EAT)
		printf("is eating\n");
	else if (status == SLEEP)
		printf("is sleeping\n");
	else if (status == THINK)
		printf("is thinking\n");
	else if (status == DIE)
		printf("died\n");
	pthread_mutex_unlock(&ph->info->status);
}
