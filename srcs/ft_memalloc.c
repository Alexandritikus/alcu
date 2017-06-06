/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:10:05 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:10:13 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = (void*)malloc(size);
	if (!fresh)
		return (NULL);
	else
		ft_bzero(fresh, size);
	return (fresh);
}
