#include <stdio.h>
#include <stdlib.h>

void	put_array(int *tab, int size)
{
	int i = 0;

	printf("[");
	while (i < size - 1)
		printf("%d, ", tab[i++]);
	printf("%d]\n\n", tab[i]);
}

void	ft_swap(int *x, int *y)
{
	int	nbr;

	nbr = *y;
	*y = *x;
	*x = nbr;
}

int	*find_max(int *tab, int size)
{
	int	i;
	int	*max;
	i = 1;
	max = &tab[0];
	while(i < size)
	{
		if (tab[i] > *max)
			max = &tab[i];
		i++;
	}
	return (max);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*max;
	int	last;
	int	count;

	count = 0;
	last = size - 1;
	while (0 < (last + 1))
	{
		if (*(max = find_max(tab, (last + 1))) > tab[last])
		{
			printf("swap: %d <-> %d\n\n", *max, tab[last]);
			ft_swap(max, &tab[last]);
			put_array(tab, size);
			count++;
		}
		last--;
	}
	printf("Total swaps: %d\n", count);
}

void	fill_tab(char **argv, int *tab, int size)
{
	int	i = 0;
	while (i < size)
	{
		tab[i] = atoi(argv[i + 1]);
		if (tab[i] == 0 && *argv[i + 1] != '0')
		{
			printf("Argumento %d não é um número\n", i + 1);
			free(tab);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	size;

	if (argc < 2)
	{
		printf("Passe numeros para serem ordenados como argumentos");
		return (2);
	}
	size = argc - 1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
	{
		free(tab);
		return (1);
	}
	fill_tab(argv, tab, size);
	put_array(tab, size);
	ft_sort_int_tab(tab, size);
	free(tab);
	return (0);
}
