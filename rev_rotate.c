/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:33:53 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/01 16:03:43 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*pre_last;

	if (!*stack || !(*stack)->next)
		return ;
	pre_last = *stack;
	last = lstlast(*stack);
	while (pre_last->next != last)
		pre_last = pre_last->next;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	pre_last->next = NULL;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	rev_rotate (a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate (b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate (a);
	rev_rotate (b);
	write(1, "rrr\n", 4);
}
