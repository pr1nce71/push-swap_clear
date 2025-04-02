/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:25:59 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/25 17:08:05 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*parse_all(char **argv)
{
	t_stack_node	*a;
	t_stack_node	*new;
	int				i;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		if (i == 1)
			a = lstnew(atoi(argv[i]));
		else
		{
			new = lstnew(atoi(argv[i]));
			if (!new)
				return (NULL);
			lstadd_last(&a, new);
		}
		i++;
	}
	return (a);
}
