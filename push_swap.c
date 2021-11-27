/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:58:18 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/27 19:29:50 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if(av[i][j] == '-')
				j++;
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
	int				*a;
	long long int	num;
	int				i;

	i = 1;
	a = (int *)ft_calloc(sizeof(int) * (ac - 1));
	if (!a)
		return (0);
	while (i < ac)
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
	int i = 1;
	while (i < ac)
	{
		printf("%d, ", a[i]);
		i++;
	}
	free(a);
}
