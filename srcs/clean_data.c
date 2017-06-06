/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:17:23 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/20 16:59:17 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	clean_data(t_data **data)
{
	t_board	*current;

	current = (*data)->board;
	while (current)
	{
		(*data)->board = (*data)->board->next;
		free(current);
		current = (*data)->board;
	}
	free(*data);
	*data = NULL;
}
