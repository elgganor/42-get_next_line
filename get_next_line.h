/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:53:30 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/12 10:53:54 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *buf, char *tmp);
void	ft_strjoin_free(char **str, char *buf);
void	get_line(char **line, char **str, int index);
int		check_line_break(char *str);
int		check_error(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
#endif
