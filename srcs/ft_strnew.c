/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:10:38 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:01:40 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc((size + 1) * sizeof(char)));
}