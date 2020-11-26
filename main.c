#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		o;
	char	*str;
	int		fd;
	int		tmp;

	i = 0;
	while (++i < argc)
	{
		printf("FILE #%d : \"%s\"\n", i, argv[i]);
		o = -1;
		str = NULL;
		fd = open(argv[i], O_RDONLY);
		while ((tmp = get_next_line(fd, &str)) == 1)
		{
//			printf("Line #%d :\n", ++o);
			printf("%s\n", str);
		}
		printf("exit code: %d\n\n", tmp);
		free(str);
	}
}
