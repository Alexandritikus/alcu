/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:34:10 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:41:22 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	ask_for_match(int max_num)
{
	ft_putstr(YELLOW_PRINT_ON);
	ft_putstr("Please set number between 1 and ");
	ft_putnbr(max_num);
	ft_putchar('\n');
	ft_putstr(COLOR_PRINT_OFF);
}

void	print_winner(int player_id)
{
	if (player_id == 0)
	{
		ft_putstr(GREEN_PRINT_ON);
		ft_putendl("Congratulations!!! You won!");
		ft_putstr(COLOR_PRINT_OFF);
	}
	else
	{
		ft_putstr(RED_PRINT_ON);
		ft_putendl("Hahahaha!!! Looooser!!!");
		ft_putstr(COLOR_PRINT_OFF);
	}
}

void	print_board(t_board *begin)
{
	t_board	*current;
	int		count;

	current = begin;
	while (current != NULL)
	{
		count = current->n_matches;
		while (count-- > 0)
			ft_putchar('|');
		ft_putchar('\n');
		current = current->prev;
	}
}

void	motivate(void)
{
	ft_putstr(BLUE_PRINT_ON);
	ft_putendl("Go go go!!! You have good chanses!!!");
	ft_putstr(COLOR_PRINT_OFF);
}

void	demotivate(void)
{
	ft_putstr(RED_PRINT_ON);
	ft_putendl("You will loose anyway, but you can try.");
	ft_putstr(COLOR_PRINT_OFF);
}
