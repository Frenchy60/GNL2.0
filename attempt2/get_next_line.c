/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:00:28 by agraton           #+#    #+#             */
/*   Updated: 2020/12/03 16:28:34 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_get_fd(int fd, char **arr)
{
	int		i;

	i = -1;
	while (++i < OPEN_MAX)
	{
		if (((int *)(arr[i]))[0] == fd)
			return (&(arr[i][4]));
		if (((int *)(arr[i]))[0] == 0)
		{
			((int *)(arr[i]))[0] == fd;
			return (&(arr[i][4]));
		}
	}
	return (NULL);
}

int			ft_contains(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char		*ft_strjoin(char *s1, char *s2, int s2size)
{
	char	*newstr;
	int		s1size;
	int		i;
	int		o;

	s1size = 0;
	while (s1[s1size])
		s1size++;
	if (!(newstr = malloc(sizeof(char) * (s1size + s2size + 1))))
		return (NULL);
	i = -1;
	while (++i < s1size)
		newstr[i] = s1[i];
	o = -1;
	while (++o < s2size)
		newstr[i++] = s2[o];
	newstr[i] = 0;
	free(s1);
	return (newstr);
}

int			ft_close_fd(int fd, char *buff, char **arr)
{
	int		i;
	int		o;

	i = -1;
	free(buff);
	if (!fd)
		return (0);
	while (++i < OPEN_MAX)
	{
		if (((int *)(arr[i]))[0] == fd)
		{
			((int *)(arr[i]))[0] = 0;
			arr[i][4] = 0;
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		arr[OPEN_MAX][BUFFER_SIZE + 1 + 4];
	char			*buff;
	char			*mem;
	int				readn;
	
	if (!*line || !(mem = ft_get_fd(fd, (char **)arr)) || 
			!(buff = malloc(sizeof(char) * (BUFFER_SIZE))))
		return (-1);
	if (!(*line = malloc(sizeof(char) * 1)))
		return (ft_close_fd(0, buff, arr));
	line[0][0] = 0;
	while (!ft_contains(*line, '\n') && (readn = read(fd, buff, BUFFER_SIZE)))
	{
		
	}
}






