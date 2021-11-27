#include "push_swap.h"

int	ft_atoi(char *str)
{
	int				neg;
	int				i;
	long long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

char	*ft_calloc(int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return (str);
}
