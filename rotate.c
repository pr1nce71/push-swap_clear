/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:33:56 by yevkahar          #+#    #+#             */
/*   Updated: 2025/03/27 16:03:53 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*back;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	back = lstlast(*stack);
	*stack = head ->next;
	(*stack)->prev = NULL;
	head ->next = NULL;
	head ->prev = back;
	back ->next = head;
}

void	ra(t_stack_node **a)
{
	rotate (a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate (b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate (a);
	rotate (b);
	write(1, "rr\n", 3);
}
