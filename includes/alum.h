/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:13:13 by oshudria          #+#    #+#             */
/*   Updated: 2017/06/06 18:03:28 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include <fcntl.h>
# include "libft.h"

# define BLUE_PRINT_ON "\e[38;5;69m"
# define RED_PRINT_ON "\e[38;5;196m"
# define GREEN_PRINT_ON "\e[38;5;46m"
# define YELLOW_PRINT_ON "\e[38;5;226m"
# define COLOR_PRINT_OFF "\e[0m"

typedef struct		s_board
{
	int				n_matches;
	int				start;
	struct s_board	*next;
	struct s_board	*prev;
}					t_board;

typedef struct		s_data
{
	t_board			*board;
	t_board			*begin;
	int				n_lines;
	int				total_num;
}					t_data;

t_data				*parse_input_board(int fd);
int					get_user_num(int max_num);
void				clean_data(t_data **data);
void				play(t_data *data);
int					first_start_to_last_match(int n_matches, int last);
int					ai_algo(t_data **data);
int					update_data(t_data **data, int user_num);
void				ask_for_match(int max_num);
void				print_winner(int player_id);
void				print_board(t_board *begin);
void				motivate(void);
void				demotivate(void);

#endif
