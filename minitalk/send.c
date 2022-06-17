/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:35:29 by song-yejin        #+#    #+#             */
/*   Updated: 2021/08/07 18:43:47 by song-yejin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

void	handler_sig(int signo)
{
	if (signo == SIGUSR1)
		g_flag = 1;
	else
		g_flag = 0;
}

int	send_char(pid_t pid, const char c)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
			return (MINITALK_EKILL);
		usleep(SLEEP_TIME);
	}
	return (0);
}

int	connect(pid_t pid)
{
	if (pid < 1)
		return (MINITALK_EINVAL);
	if (signal(SIGUSR1, handler_sig) == SIG_ERR || \
	signal(SIGUSR2, handler_sig) == SIG_ERR)
		return (MINITALK_ESIGNAL);
	if (kill(pid, SIGUSR1) == -1)
		return (MINITALK_EKILL);
	usleep(SLEEP_TIME);
	if (g_flag == 0)
		return (MINITALK_ECONN);
	g_flag = 0;
	return (MINITALK_OK);
}

int	send_null(pid_t pid)
{
	send_char(pid, '\0');
	usleep(SLEEP_TIME);
	if (g_flag)
		return (0);
	while (g_flag == 0)
	{
		send_char(pid, '\0');
		usleep(SLEEP_TIME);
	}
	return (MINITALK_ESEND);
}

int	send(pid_t pid, const char *msg)
{
	int	ret;

	ret = connect(pid);
	if (ret != MINITALK_OK)
		return (ret);
	while (*msg)
	{
		ret = send_char(pid, *msg);
		if (ret != MINITALK_OK)
			return (ret);
		++msg;
	}
	ret = send_null(pid);
	if (ret != MINITALK_OK)
		return (ret);
	ft_putstr_fd("Success to send\n", 1);
	return (MINITALK_OK);
}
