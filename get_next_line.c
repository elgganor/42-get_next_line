/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/12 11:33:08 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (0);
	return (1);
}

int		check_line_break(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

void	get_line(char **line, char **str, int index, int step)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(*line = (char *)ft_calloc(index + 1, sizeof(char))))
		return ;
	while (i < index)
	{
		(*line)[i] = (*str)[i];
		i++;
	}
	(*line)[i] = '\0';
	tmp = ft_strdup(*str);
	free(*str);
	*str = (step == 1) ? NULL : ft_strdup(tmp + index + 1);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	int			r;
	char		*buf;

	if (check_error(fd, line) == 0
			|| !(buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	while (check_line_break(str) == -1 && (r = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if ((r == -1) || (buf[r] = '\0'))
			return (-1);
		ft_strjoin_free(&str, buf);
	}
	free(buf);
	if ((check_line_break(str) != -1))
	{
		get_line(line, &str, check_line_break(str), 0);
		return (1);
	}
	if (r == 0 && (str != NULL))
	{
		get_line(line, &str, ft_strlen(str), 1);
		return (1);
	}
	return (0);
}
