/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:06:28 by agraton           #+#    #+#             */
/*   Updated: 2021/08/06 17:17:05 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (printf("DUMBASS!!\n"));
	int	fd = open(argv[1], O_RDONLY);
	char	*str = NULL;
	int		i = 0;
	while ((str = get_next_line(fd)) && i++ < 1000)
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
