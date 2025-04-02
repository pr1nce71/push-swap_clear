/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:28 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 15:46:53 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	set_index(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*min;
	int				index;

	index = 0;
	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	while (index < stack_length(stack))
	{
		current = stack;
		min = NULL;
		while (current)
		{
			if (current->index == -1 && (!min || current->data < min->data))
				min = current;
			current = current->next;
		}
		if (min)
			min->index = index++;
	}
}
//set index to each number in stack

int	find_min_index(t_stack_node *stack)
{
	t_stack_node	*current;
	int				min_index;

	if (!stack)
		return (0);
	current = stack;
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}
