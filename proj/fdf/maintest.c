#include "libft.h"

#define XMAX 1
#define YMAX 2

int		main()
{
	int			***mat;
	int			i;
	int			j;
	int			k;

//	ft_printf("{green}%s{eoc}\n", "INIT...");
	
	mat = (int ***)malloc(sizeof(int **) * YMAX + 1);
	i = 0;
	while (i <= YMAX)
	{
		mat[i] = (int **)malloc(sizeof(int *) * XMAX + 1);
		j = 0;
		while (j <= XMAX)
		{
			mat[i][j] = (int *)malloc(sizeof(int) * 3);
			k = 0;
			while (k <= 2)
			{
				mat[i][j][k] = -1;
				k++;
			}
			j++;
		}
		i++;
	}

//	ft_printf("{green}%s{eoc}\n", "MAT CREATE FINISH...");

	i = 0;
	while (i <= YMAX)
	{
		j = 0;
		while (j <= XMAX)
		{
			k = 0;
			while (k <= 2)
			{
				if (mat[i][j][k] != -1)
					ft_printf("(%d, %d, %d)-[%d]\n", i, j, k, mat[i][j][k]);
				k++;
			}
			j++;
		}
		i++;
	}

//	ft_printf("{green}%s{eoc}\n", "MAT DUMP FINISH...");

	i = 0;
	while (i <= YMAX)
	{
		j = 0;
		while (j <= XMAX)
		{
			free(mat[i][j]);
			j++;
		}
		free(mat[i]);
		i++;
	}
	free(mat);

//	ft_printf("{green}%s{eoc}\n", "MAT FREE FINISH...");

	return (0);
}


