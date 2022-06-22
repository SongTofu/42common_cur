/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:45:29 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/11 02:38:14 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!(ret = ft_calloc(len + 1, 1)))
		return (0);
	i = 0;
	tmp = ret;
	while (i < len)
	{
		*tmp = (*f)(i, *s);
		tmp++;
		i++;
		s++;
	}
	return (ret);
}
