/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:12 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 15:48:22 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*lstadd_last(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (!new)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	last = lstlast(*lst);
	last ->next = new;
	return (new);
}

int	atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-')
		sign *= -1;
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
