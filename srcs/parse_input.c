/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:06:53 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 15:47:31 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static t_data	*create_data(void)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->board = NULL;
	data->begin = NULL;
	data->n_lines = 0;
	data->total_num = 0;
	return (data);
}

static int		is_valid(char *buf)
{
	char	*p;
	int		num;

	if (buf == NULL)
		return (-1);
	if (*buf == '0')
		return (-1);
	p = buf;
	num = -1;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (-1);
		p++;
	}
	if (p - buf > 5)
		return (-1);
	num = ft_atoi(buf);
	if (num > 0 && num <= 10000)
		return (num);
	return (-1);
}

static void		create_node(t_data **data, int num)
{
	t_board	*first;

	first = (t_board*)malloc(sizeof(t_board));
	first->n_matches = num;
	first->next = (*data)->board;
	first->prev = NULL;
	if (first->next != NULL)
	{
		first->start = first_start_to_last_match(num, !first->next->start);
		first->next->prev = first;
	}
	else
	{
		first->start = first_start_to_last_match(num, 0);
		(*data)->begin = first;
	}
	(*data)->board = first;
	(*data)->n_lines += 1;
	(*data)->total_num += num;
}

t_data			*parse_input_board(int fd)
{
	t_data	*data;
	char	*buf;
	int		valid;
	int		num;

	data = create_data();
	buf = NULL;
	valid = 1;
	num = -1;
	while (valid && get_next_line(fd, &buf) > 0)
	{
		if (fd == 0 && buf == NULL)
			break ;
		if ((num = is_valid(buf)) != -1)
			create_node(&data, num);
		else
			valid = 0;
		ft_strdel(&buf);
	}
	if (valid == 0 || data->begin == NULL)
		clean_data(&data);
	return (data);
}

int				get_user_num(int max_num)
{
	char	*buf;
	int		num;

	buf = NULL;
	num = -1;
	if (get_next_line(0, &buf))
	{
		num = is_valid(buf);
		if (num < 1 || num > max_num)
			num = -1;
		ft_strdel(&buf);
	}
	return (num);
}
