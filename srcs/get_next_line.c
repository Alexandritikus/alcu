/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:04:57 by oshudria          #+#    #+#             */
/*   Updated: 2017/05/21 14:01:45 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static char		*ft_strxjoin(char *s1, char const *s2)
{
	char	*fresh;
	size_t	len;

	fresh = NULL;
	len = ft_strlen(s2) + (s1 == NULL ? 0 : ft_strlen(s1));
	if (len == 0)
		return (s1);
	fresh = ft_strnew(len);
	if (s1)
		ft_strcpy(fresh, s1);
	else
	{
		ft_strcpy(fresh, s2);
		return (fresh);
	}
	ft_strcat(fresh, s2);
	ft_strdel(&s1);
	return (fresh);
}

static t_line	*gnl_update(t_line **next_line, const int fd)
{
	while (*next_line && (*next_line)->fd != fd)
	{
		if ((*next_line)->fd == fd)
			return (*next_line);
		next_line = &(*next_line)->next;
	}
	if (!(*next_line))
	{
		*next_line = malloc(sizeof(**next_line));
		(*next_line)->fd = fd;
		(*next_line)->next = NULL;
		(*next_line)->str = NULL;
	}
	return (*next_line);
}

static int		gnl_read_tmp(char **line, t_line *cur)
{
	char	*tmp;
	char	*tmp2;

	if (!cur->str)
		return (0);
	if ((tmp = ft_strchr(cur->str, '\n')))
	{
		tmp2 = ft_strsub(cur->str, 0, tmp - cur->str);
		*line = ft_strxjoin(*line, tmp2);
		ft_strdel(&tmp2);
		tmp2 = cur->str;
		cur->str = ft_strdup(tmp + 1);
		ft_strdel(&tmp2);
		return (1);
	}
	else
	{
		*line = ft_strxjoin(*line, cur->str);
		ft_strdel(&(cur->str));
	}
	return (0);
}

static int		gnl_read_fd(char **line, t_line *current, char *buf)
{
	int		ret;
	char	*tmp;
	char	*tmp2;

	while ((ret = (int)read(current->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			tmp2 = ft_strsub(buf, 0, tmp - buf);
			*line = ft_strxjoin(*line, tmp2);
			ft_strdel(&tmp2);
			tmp2 = current->str;
			current->str = ft_strdup(tmp + 1);
			ft_strdel(&tmp2);
			return (1);
		}
		else
			*line = ft_strxjoin(*line, buf);
	}
	if (!(*line) || (ret == 0 && *line && **line == '\0'))
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*next_line = NULL;
	t_line			*current;
	char			*buf;
	int				reading;

	if (!line || fd < 0 || read(fd, *line, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (*line)
		*line = NULL;
	current = gnl_update(&next_line, fd);
	if (gnl_read_tmp(line, current))
	{
		free(buf);
		return (1);
	}
	reading = gnl_read_fd(line, current, buf);
	free(buf);
	return (reading);
}
