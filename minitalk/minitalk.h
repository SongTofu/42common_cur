/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:38:31 by song-yejin        #+#    #+#             */
/*   Updated: 2021/08/07 19:11:21 by song-yejin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define SLEEP_TIME	100

# define MINITALK_OK	0
# define MINITALK_EINVAL	-1
# define MINITALK_ESIGNAL	-2
# define MINITALK_EKILL		-3
# define MINITALK_ECONN		-4
# define MINITALK_ESEND		-5

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
int		send(pid_t pid, const char *msg);

#endif
