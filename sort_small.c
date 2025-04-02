/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:54:17 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 16:20:43 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **stack)
{
	if ((*stack)->data > (*stack)->next->data)
	sa(stack);
}

void	sort_three(t_stack_node **stack_a)

{
	int	first;
	int	second;
	int	third;
	
	if (!(*stack_a)->next->next)
	return ;
	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first < third && third < second)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > third && first < second)
	rra(stack_a);
	else if (second < third && third < first)
	ra(stack_a);
	else if (first > second && first < third)
	sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int smallest;
	smallest = find_min_index(*a);
	
	while ((*a)->index != smallest)
	ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int smallest;
	smallest = find_min_index(*a);
	
	while ((*a)->index != smallest)
	ra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = stack_length(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
