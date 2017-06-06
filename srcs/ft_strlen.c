/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:19:09 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:08:23 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

size_t	ft_strlen(const char *s)
{
	const char *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}
