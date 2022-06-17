/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:59:20 by song-yejin        #+#    #+#             */
/*   Updated: 2021/08/07 18:43:39 by song-yejin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_error(int error_num)
{
	ft_putstr_fd("ERROR :: ", 1);
	if (error_num == MINITALK_EINVAL)
		ft_putstr_fd("Invalid argument\n", 1);
	else if (error_num == MINITALK_ESIGNAL)
		ft_putstr_fd("Failed to set signal handler\n", 1);
	else if (error_num == MINITALK_EKILL)
		ft_putstr_fd("Failed to send signal\n", 1);
	else if (error_num == MINITALK_ECONN)
		ft_putstr_fd("Failed to connect server\n", 1);
	else if (error_num == MINITALK_ESEND)
		ft_putstr_fd("Failed to send message\n", 1);
	return (1);
}

int	ck_ag(int ac, char **ag)
{
	if (ac != 3)
		return (-1);
	return (ft_atoi(ag[1]));
}

int	main(int ac, char **ag)
{
	pid_t	pid;
	int		ret;

	pid = ck_ag(ac, ag);
	ret = send(pid, ag[2]);
	if (ret != MINITALK_OK)
		return (ft_error(ret));
	return (0);
}
