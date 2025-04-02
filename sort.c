/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:33:58 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 13:01:57 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_first_cost(t_stack_node *stack)
{
	t_stack_node	*current;
	int				size;
	int				pivot;

	size = stack_length(stack);
	pivot = size / 2;
	current = stack;
	while (current)
	{
		if (current->index <= pivot)
			current->primary_cost = current->index;
		else
			current->primary_cost = size - current->index;
		current = current->next;
	}
}

static int	max(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	pos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	calculate_last_cost(t_stack_node *stack_b)
{
	t_stack_node	*current;
	int				final_cost;

	current = stack_b;
	while (current)
	{
		if (current->primary_cost >= 0 && current->final_cost >= 0)
			final_cost = max(current->primary_cost, current->final_cost);
		else if (current->primary_cost < 0 && current->final_cost < 0)
			final_cost = max(pos(current->primary_cost),
					pos(current->final_cost));
		else
			final_cost = pos(current->primary_cost) + pos(current->final_cost);
		current->final_cost = final_cost;
		current = current->next;
	}
}

int	find_target_index(t_stack_node *stack_a, int b_index)
{
	t_stack_node	*current_a;
	int				target_pos;
	int				target_index;

	target_index = INT_MAX;
	current_a = stack_a;
	while (current_a)
	{
		if (current_a->index > b_index
			&& current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->index;
		}
		current_a = current_a->next;
	}
	if (target_index == INT_MAX)
		return (find_min_index(stack_a));
	return (target_pos);
}
