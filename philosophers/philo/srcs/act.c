/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:17:45 by song-yejin        #+#    #+#             */
/*   Updated: 2021/10/20 16:30:41 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	if (ph->info->num_philo == 1)
	{
		pthread_mutex_lock(&ph->info->fork[ph->r_f]);
		print_status(ph, FORK);
		while (!ph->info->stop)
			usleep(1000);
		pthread_mutex_unlock(&ph->info->fork[ph->r_f]);
	}
	else
	{
		pthread_mutex_lock(&ph->info->fork[ph->r_f]);
		print_status(ph, FORK);
		pthread_mutex_lock(&ph->info->fork[ph->l_f]);
		print_status(ph, FORK);
		pthread_mutex_lock(&ph->lock);
		print_status(ph, EAT);
		ph->start_time = real_time();
		pthread_mutex_unlock(&ph->lock);
		while (real_time() - ph->start_time <= ph->info->time_eat && \
		!ph->info->stop)
			usleep(1000);
		ph->meal++;
		pthread_mutex_unlock(&ph->info->fork[ph->r_f]);
		pthread_mutex_unlock(&ph->info->fork[ph->l_f]);
	}
}

void	sleeping(t_philo *ph)
{
	int	start;

	start = real_time();
	print_status(ph, SLEEP);
	while (real_time() - start <= ph->info->time_sleep && !ph->info->stop)
		usleep(1000);
}

void	thinking(t_philo *ph)
{
	print_status(ph, THINK);
}

void	*routine(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->n % 2 == 0 && ph->info->num_philo != 1)
		usleep(1000 * ph->info->time_eat);
	while (!ph->info->stop)
	{
		eating(ph);
		if (ph->info->must_eat != -1 && ck_meal(ph))
			break ;
		if (ph->info->stop)
			break ;
		sleeping(ph);
		if (ph->info->stop)
			break ;
		thinking(ph);
		if (ph->info->stop)
			break ;
	}
	return (NULL);
}

int	ck_meal(t_philo *ph)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < ph->info->num_philo)
	{
		if (ph->info->ph[i].meal < ph->info->must_eat)
			return (RET_SUCCESS);
	}
	ph->info->stop = 1;
	return (RET_ERROR);
}
