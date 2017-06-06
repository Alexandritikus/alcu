/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:23:04 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 15:26:31 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static void	print_ai(int num)
{
	ft_putstr(BLUE_PRINT_ON);
	ft_putstr("AI took ");
	ft_putnbr(num);
	ft_putendl(" matches");
	ft_putstr(COLOR_PRINT_OFF);
}

int			first_start_to_last_match(int n_matches, int last)
{
	int	first_to_last;

	if (n_matches == 2 || n_matches)
		if (last && n_matches <= 3)
			return (1);
	first_to_last = (n_matches - 1) % 4;
	if ((first_to_last == 0 && last == 1) || (first_to_last != 0 && last == 0))
		return (1);
	else
		return (0);
}

static int	pseudo_rand(int max)
{
	static int	num = 0;

	if (num == 3)
		num = 1;
	else
		num += 1;
	return (MIN(num, max));
}

int			ai_algo(t_data **data)
{
	int			comp_num;
	int			finish;
	const int	k = (*data)->board->n_matches;

	comp_num = 0;
	if ((*data)->board->next == NULL)
		finish = 0;
	else
		finish = !(*data)->board->next->start;
	if (finish == 0)
		comp_num = ((k - 1) % 4 != 0 ? (k - 1) % 4 : pseudo_rand(k));
	else if (finish == 1)
	{
		if (k <= 3)
			comp_num = k;
		else if (k % 4 == 0)
			comp_num = pseudo_rand(k);
		else
			comp_num = k % 4;
	}
	print_ai(comp_num);
	if (*data)
		if (update_data(data, comp_num) == 0)
			return (0);
	return (1);
}
