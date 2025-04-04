/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:16:27 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/04 14:48:46 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	int				size;
	int				pivot;
	int				pushed;

	size = stack_length(*a);
	pivot = size / 2;
	pushed = 0;
	current = *a;
	while (size - pivot > 3 && current)
	{
		if (current->index <= pivot)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		current = *a;
	}
	while (stack_length(*a) > 3)
		pb(a, b);
}

void	find_target_position(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;

	current_b = stack_b;
	while (current_b)
	{
		current_b->target_number = find_target_index(stack_a, current_b->index);
		current_b = current_b->next;
	}
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
