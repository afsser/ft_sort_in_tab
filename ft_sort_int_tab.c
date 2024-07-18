#include <stdio.h>
#include <stdlib.h>

void	put_array(int *tab, int size)
{
	int i = 0;

	printf("[");
	while (i < size - 1)
	{
		printf("%d, ", tab[i]);
		i++;
	}
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
	int	i;
	int	*max;
	int	last;

	i = 0;
	last = size - 1;
	while (i < (last + 1))
	{
		if (*(max = find_max(tab, (last + 1))) > tab[last])
		{
			printf("swap: %d <-> %d\n\n", *max, tab[last]);
			ft_swap(max, &tab[last]);
			put_array(tab, size);
		}
		last--;
	}
}

void	fill_tab(char **argv, int *tab, int size)
{
	int	i = 0;
	while (i < size)
	{
		tab[i] = atoi(argv[i + 1]);
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
		return(2);
	}
	size = argc - 1;
	tab = malloc(sizeof(int) * size);
	fill_tab(argv, tab, size);
	if (!tab)
	{
		free(tab);
		return (1);
	}
	// int tab[8] = {78, 23, 1, 3, 48, 5, 17, 59};
	put_array(tab, size);
	ft_sort_int_tab(tab, size);
	return (0);
}