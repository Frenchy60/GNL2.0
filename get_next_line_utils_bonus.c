/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:55:29 by agraton           #+#    #+#             */
/*   Updated: 2021/08/07 16:34:32 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlenc(char *str, char stop)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != stop)
		i++;
	return (i);
}

char	*ft_error(char *str)
{
	if (str)
		free(str);
	return (NULL);
}
