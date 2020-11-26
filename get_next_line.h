/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:31:09 by agraton           #+#    #+#             */
/*   Updated: 2020/11/26 12:56:07 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE = 10

typedef struct	s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(char *content, int fd, t_list *next);
t_list			*ft_lstsearch(t_list **lst, int fd);

#endif
