/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yjsong0502@daum.net>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:53:46 by yejsong           #+#    #+#             */
/*   Updated: 2021/01/22 22:53:50 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
# define RET_SUCCESS 1
# define RET_ERROR -1
# define RET_EOF 0

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t number, size_t size);
void	ft_free(char **s1);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t count);
int		ft_strappend(char **line, char *buf);
#endif
