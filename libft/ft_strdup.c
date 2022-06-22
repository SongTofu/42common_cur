/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 01:34:29 by yejsong           #+#    #+#             */
/*   Updated: 2020/11/08 01:56:44 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str);
	ret = ft_calloc(len + 1, 1);
	ft_strlcpy(ret, str, len + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
