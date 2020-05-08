/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:03:31 by jinwkim           #+#    #+#             */
/*   Updated: 2020/05/06 20:07:14 by jinwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_is_buffer_line(char *line, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (line[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int		ft_clear(char **sub, char **tmp, t_info *info, char **line)
{
	if ((tmp != 0) && (*tmp != 0))
		free(*tmp);
	if ((sub != 0) && (*sub != 0))
		free(*sub);
	if (info->old != 0)
	{
		free(info->old);
		info->old = 0;
	}
	if (line != 0 && *line != 0)
	{
		free(*line);
		*line = 0;
	}
	return (-1);
}

int		ft_line_realloc(char **line, char *tmp, char *sub, t_info *info)
{
	free(*line);
	*line = tmp;
	free(info->old);
	info->old = sub;
	info->len = ft_strlen(info->old);
	if (info->index != -1)
		return (1);
	else
		return (0);
}

int		ft_new_insert_line(char **line, char *buf, t_info *info, int ret)
{
	char	*tmp;
	char	*sub;

	tmp = 0;
	sub = 0;
	if ((info->index = ft_is_buffer_line(buf, ret)) != -1)
	{
		if ((sub = ft_substr(buf, 0, info->index)) == 0)
			return (ft_clear(&sub, &tmp, info, line));
		if ((tmp = ft_strjoin(*line, sub)) == 0)
			return (ft_clear(&sub, &tmp, info, line));
		free(sub);
		if ((sub = ft_substr(buf, info->index + 1,
				ft_strlen(buf) - info->index)) == 0)
			return (ft_clear(&sub, &tmp, info, line));
	}
	else
	{
		if ((tmp = ft_strjoin(*line, buf)) == 0)
			return (ft_clear(&sub, &tmp, info, line));
		if ((sub = (char *)ft_calloc(1, sizeof(char))) == 0)
			return (ft_clear(&sub, &tmp, info, line));
	}
	return (ft_line_realloc(line, tmp, sub, info));
}

int		get_next_line(int fd, char **line)
{
	static t_info	info[1024];
	char			new_buf[BUFFER_SIZE + 1];

	if ((fd < 0) || (fd > 1024) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	*line = (char *)ft_calloc(1, sizeof(char));
	if (info[fd].old == 0)
	{
		info[fd].old = (char *)ft_calloc(1, sizeof(char));
		info[fd].len = 0;
	}
	if (((info[fd].val = ft_new_insert_line(line, info[fd].old, &(info[fd]),
						info[fd].len)) == 1) || (info[fd].val == -1))
		return (info[fd].val);
	while ((info[fd].ret = read(fd, new_buf, BUFFER_SIZE)) > 0)
	{
		new_buf[info[fd].ret] = 0;
		if (((info[fd].val = ft_new_insert_line(line, new_buf, &(info[fd]),
							info[fd].ret)) == 1) || (info[fd].val == -1))
			return (info[fd].val);
	}
	if ((*line != 0) && (info[fd].ret == 0))
		return (0);
	return (ft_clear(0, 0, &(info[fd]), line));
}
