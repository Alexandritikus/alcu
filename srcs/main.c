/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:14:13 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 15:22:31 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static int	get_file_descriptor(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc == 1)
	{
		ft_putstr(BLUE_PRINT_ON);
		ft_putendl("Please, enter the map from keyboard");
		ft_putstr(COLOR_PRINT_OFF);
		return (fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 2)
			return (fd);
		return (-1);
	}
}

int			main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	data = NULL;
	if (argc > 2)
		write(2, "ERROR\n", 6);
	else
	{
		if ((fd = get_file_descriptor(argc, argv)) == -1)
			write(2, "ERROR\n", 6);
		else if ((data = parse_input_board(fd)) == NULL)
			write(2, "ERROR\n", 6);
		else
		{
			play(data);
			clean_data(&data);
		}
		close(fd);
	}
	return (0);
}
