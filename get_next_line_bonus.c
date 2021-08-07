/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:19:00 by agraton           #+#    #+#             */
/*   Updated: 2021/08/07 16:34:09 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_contains(char *str, char stop)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == stop)
			return (1);
	return (0);
}

char	*ft_strjoinc(char *str, char *str2, char stop)
{
	int		i[3];
	char	*newstr;

	i[0] = ft_strlenc(str2, stop);
	i[1] = ft_strlenc(str, stop);
	newstr = malloc(sizeof(char) * (i[0] + i[1] + 2));
	if (!newstr)
	{
		if (str)
			free(str);
		return (NULL);
	}
	i[2] = -1;
	while (++i[2] < i[1])
		newstr[i[2]] = str[i[2]];
	i[2] = -1;
	while (++i[2] < i[0])
		newstr[i[1] + i[2]] = str2[i[2]];
	if (str2[i[2]] == '\n')
		newstr[i[0]++ + i[1]] = '\n';
	newstr[i[0] + i[1]] = '\0';
	if (str)
		free(str);
	return (newstr);
}

void	ft_strmove(char *str, char stop)
{
	int	size;
	int	i;

	size = ft_strlenc(str, stop);
	i = 1;
	if (str[size])
	{
		while (str[size + i])
		{
			str[i - 1] = str[size + i];
			i++;
		}
	}
	i--;
	str[i++] = '\0';
}

char	*get_next_line_end(char *buffer, char *newline, int readn)
{
	ft_strmove(buffer, '\n');
	if (!newline || (!(ft_strlenc(newline, '\n')
				+ ft_strlenc(buffer, '\n')) && !readn))
		return (ft_error(newline));
	return (newline);
}

char	*get_next_line(int fd)
{
	static char		buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char			*newline;
	int				readn;

	if (fd <= 0 || fd >= OPEN_MAX)
		return (NULL);
	readn = BUFFER_SIZE;
	newline = NULL;
	if (ft_strlenc(buffer[fd], '\0'))
	{
		newline = ft_strjoinc(newline, buffer[fd], '\n');
		if (!newline)
			return (NULL);
	}
	while (!ft_contains(buffer[fd], '\n') && readn == BUFFER_SIZE)
	{
		readn = read(fd, buffer[fd], BUFFER_SIZE);
		if (readn < 0)
			return (ft_error(newline));
		buffer[fd][readn] = '\0';
		newline = ft_strjoinc(newline, buffer[fd], '\n');
		if (!newline)
			return (NULL);
	}
	return (get_next_line_end((char *)(buffer[fd]), newline, readn));
}
