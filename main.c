/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:59:13 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/04 14:47:46 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
stack_b_cheapest_node = find_cheapest_node(stack_b);
while (stack_b_cheapest_node->data != stack_b->data)
{
	if (stack_b_cheapest_node->next->data == stack_b->data)
	{
		sb(&stack_b);
		break ;
	}
	if (stack_b_cheapest_node->sign == 1)
		rb(&stack_b);
	else
		rrb(&stack_b);
}
stack_a_target_node = find_target_node(stack_a, 
								stack_b_cheapest_node->target_number);
while (stack_a_target_node != stack_a)
{
	if (stack_a_target_node->next == stack_a)
	{
		sa(&stack_a);
		break ;
	}
	if (stack_a_target_node->sign == 1)
		ra(&stack_a);
	else
		rra(&stack_a);
}
pa(&stack_a, &stack_b);

stack_a return_target_node(stack_a stack_a, int data){
	stack_head = stack_a;
	target_node = NULL;
	
	while (stack_a)
	{
		if ((*stack_a)->data > data)
				&& (*stack_a)->data < target_node_data)
			target_node = *stack_a;
	}
}

stack_a->index = 0;
*/

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	execute_move_a(t_stack_node **a, int target_pos)
{
	t_stack_node	*current;
	int				size;
	int				middle;

	size = stack_length(*a);
	middle = size / 2;
	current = *a;
	while (current && current->index != target_pos)
	{
		if (target_pos <= middle)
			ra(a);
		else
			rra(a);
		current = *a;
	}
}

void	execute_move_b(t_stack_node **b, t_stack_node *cheapest)
{
	int	size;
	int	middle;

	size = stack_length(*b);
	middle = size / 2;
	while (cheapest->data != (*b)->data)
	{
		if (cheapest->index <= middle)
			rb(b);
		else
			rrb(b);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	while (*b)
	{
		find_target_position(*a, *b);
		calculate_first_cost(*b);
		calculate_last_cost(*b);
		cheapest = find_cheapest_node(*b);
		if (!cheapest)
			return ;
		execute_move_b(b, cheapest);
		execute_move_a(a, cheapest->target_number);
		pa(a, b);
	}
}

int	main(int argc, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (!check_for_errors(av))
		return (error_exit());
	a = parse_all(av);
	if (!a)
		return (error_exit());
	set_index(a);
	if (stack_length(a) == 2 || stack_length(a) == 3 || stack_length(a) == 4
			|| stack_length(a) == 5)
		sort_small(&a, &b);
	else if (stack_length(a) > 5)
	{
		push_to_b(&a, &b);
		sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
// errors through write(2, "Error\n", 6);