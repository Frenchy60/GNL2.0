#include <stdio.h>

int		main(void)
{
	char	arr1[10][10];
	static char	arr2[10][10];
	int		i;
	int		o;

	i = -1;
	printf("char arr[10][10]:\n");
	while (++i < 10)
	{
		o = -1;
		while (++o < 10)
			printf("%d ", (int)arr1[i][o]);
		printf("\n");
	}
	i = -1;
	printf("static char arr[10][10]:\n");
	while (++i < 10)
	{
		o = -1;
		while (++o < 10)
			printf("%d ", (int)arr2[i][o]);
		printf("\n");
	}
	return (0);
}
