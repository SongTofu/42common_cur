/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:35:50 by yejsong           #+#    #+#             */
/*   Updated: 2021/10/20 16:31:23 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	num_err(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) || ft_strlen(av[i]) > 10)
				return (RET_ERROR);
		}
	}
	return (RET_SUCCESS);
}

int	set_fork(t_info *info)
{
	int	i;

	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->num_philo);
	if (!info->fork)
		return (ft_exit("ERROR :: Malloc Return NULL\n"));
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
		{
			free(info->fork);
			return (RET_ERROR);
		}
	}
	return (RET_SUCCESS);
}

int	fill_info(int ac, char **av, t_info *info)
{
	if (num_err(av) || !(ac == 5 || ac == 6))
		return (ft_exit("ERROR :: Check Argv Form\n"));
	memset(info, 0, sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->must_eat = -1;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (info->num_philo <= 0 || info->time_die <= 0 || info->time_eat <= 0 \
	|| info->time_sleep <= 0)
		return (ft_exit("ERROR :: Check Argv From\n"));
	if (set_fork(info))
		return (ft_exit("ERROR :: Mutex Init Fail\n"));
	if (pthread_mutex_init(&info->status, NULL))
		return (ft_exit("ERROR :: Mutex Init Fail\n"));
	return (RET_SUCCESS);
}

int	set_ph(t_info *info)
{
	int	i;

	info->ph = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!info->ph)
		return (ft_exit("ERROR :: Malloc Return Null\n"));
	i = -1;
	while (++i < info->num_philo)
	{
		info->ph[i].n = i;
		info->ph[i].l_f = i;
		info->ph[i].r_f = (i + 1) % info->num_philo;
		info->ph[i].start_time = 0;
		info->ph[i].meal = 0;
		info->ph[i].info = info;
		if (pthread_mutex_init(&info->ph[i].lock, NULL))
		{
			free(info->ph);
			return (ft_exit("ERROR :: Mutex Init Fail\n"));
		}
	}
	return (RET_SUCCESS);
}

int	init(t_info *info)
{
	int	i;

	info->base_time = real_time();
	i = -1;
	while (++i < info->num_philo)
	{
		info->ph[i].start_time = real_time();
		if (pthread_create(&info->ph[i].th_philo, NULL, routine, &info->ph[i]))
			return (ft_exit("ERROR  :: thread_create Fail\n"));
		if (pthread_create(&info->ph[i].monitor, NULL, monitor, &info->ph[i]))
			return (ft_exit("ERORR :: thread create Fail\n"));
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_join(info->ph[i].th_philo, NULL))
			return (ft_exit("ERROR :: Thread Join Fail\n"));
		if (pthread_join(info->ph[i].monitor, NULL))
			return (ft_exit("ERROR :: Thread Join Fail\n"));
	}
	return (RET_SUCCESS);
}
