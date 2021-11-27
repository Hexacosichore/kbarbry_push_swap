#include "push_swap.h"

int	check_alpha(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	*ft_parse(int ac, char **av)
{
	int			*a;
	long int	num;
	int			i;

	i = 1;
	a = (int *)ft_calloc(sizeof(int) * (ac - 1));
	if (!a)
		return (0);
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		a[i - 1] = num;
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	*a;

	if (!check_alpha(ac, av))
		return (ft_error());
	a = ft_parse(ac, av);
	if (!a)
		return (ft_error());
	free(a);
}
