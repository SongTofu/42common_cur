/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 01:57:35 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/09 21:49:07 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if (!(res = (char *)ft_calloc(len + 1, 1)))
		return (0);
	if (start >= ft_strlen(s))
		return (res);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
