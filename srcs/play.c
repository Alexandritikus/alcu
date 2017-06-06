/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:54:13 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 15:04:19 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int			update_data(t_data **data, int user_num)
{
	t_board	*next_line;

	next_line = NULL;
	(*data)->board->n_matches -= user_num;
	if ((*data)->board->n_matches == 0)
	{
		next_line = (*data)->board->next;
		free((*data)->board);
		(*data)->board = next_line;
		if ((*data)->board)
			(*data)->board->prev = NULL;
		(*data)->n_lines -= 1;
	}
	(*data)->total_num -= user_num;
	if ((*data)->total_num == 0)
		return (0);
	else
		return (1);
}

void		play(t_data *data)
{
	int	user_num;
	int	player_id;

	user_num = 0;
	data->board->start ? motivate() : demotivate();
	while (data->total_num > 0)
	{
		print_board(data->begin);
		player_id = 0;
		while (!player_id)
		{
			ask_for_match(MIN(3, data->board->n_matches));
			if ((user_num = get_user_num(MIN(3, data->board->n_matches))) > 0)
				player_id = 1;
		}
		if (update_data(&data, user_num) == 0)
		{
			print_winner(player_id);
			continue ;
		}
		if (ai_algo(&data) == 0)
			print_winner(!player_id);
	}
}
