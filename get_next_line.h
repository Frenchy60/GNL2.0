/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:51:25 by agraton           #+#    #+#             */
/*   Updated: 2021/08/07 16:30:37 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define OPEN_MAX 15

char	*get_next_line(int fd);
char	*ft_error(char *str);
int		ft_strlenc(char *str, char stop);

#endif
