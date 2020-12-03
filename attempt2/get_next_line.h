/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:31:09 by agraton           #+#    #+#             */
/*   Updated: 2020/12/01 21:01:55 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 100
# define FD_MAX 5

typedef struct	s_list
{
	char			*str;
	int				fd;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
t_list			*ft_lstnew(char *content, int fd, t_list *next);
t_list			*ft_lstsearch(t_list **lst, int fd);
int				ft_strlenc(char *str, char c);
int				ft_strnadd(char **dest, char *src, int n);
char			*ft_strcutc(char **str, char c);

#endif
