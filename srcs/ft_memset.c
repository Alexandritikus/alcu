/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:23:34 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:10:06 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;

	str = s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}
