/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:15:12 by song-yejin        #+#    #+#             */
/*   Updated: 2021/10/20 16:32:08 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>

# define RET_ERROR -1
# define RET_SUCCESS 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct		s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				stop;
	int				base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	status;
	t_philo			*ph;
};

struct		s_philo
{
	int				n;
	int				r_f;
	int				l_f;
	int				start_time;
	int				meal;
	pthread_t		th_philo;
	pthread_t		monitor;
	pthread_mutex_t	lock;
	t_info			*info;
};

int		ft_exit(char *s);
int		ft_isdigit(char c);
int		ft_strlen(char *s);
int		ft_atoi(const char *s);
int		real_time(void);
int		num_err(char **av);
int		set_fork(t_info *info);
int		fill_info(int ac, char **av, t_info *info);
int		set_ph(t_info *info);
int		init(t_info *info);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);
void	*routine(void *data);
int		ck_meal(t_philo *ph);
void	print_status(t_philo *ph, int status);
void	*monitor(void *data);

#endif