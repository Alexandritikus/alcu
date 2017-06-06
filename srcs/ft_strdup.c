/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:05:49 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:08:16 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s) + 1;
	tmp = (char*)malloc(len);
	if (tmp == NULL)
		return (NULL);
	else
		return (ft_memcpy(tmp, s, len));
}
