/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:25:17 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 14:20:08 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	has_duplicate(char **av, int current)
{
	int	j;

	j = 1;
	while (av[j])
	{
		if (current != j && atoi(av[current]) == atoi(av[j]))
			return (1);
		j++;
	}
	return (0);
}

int	valid_int(char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_for_errors(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_format(av[i]) == 0)
			return (0);
		if (has_duplicate(av, i))
			return (0);
		if (!valid_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
