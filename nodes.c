/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:45:51 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 15:48:41 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*lstnew(int data)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node ->data = data;
	new_node ->next = NULL;
	new_node ->prev = NULL;
	return (new_node);
}

t_stack_node	*lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next)
		lst = lst ->next;
	return (lst);
}

t_stack_node	*create_node(int data)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack_node	*insert_node(t_stack_node *head, int data, int target_index)
{
	t_stack_node	*new_node;
	t_stack_node	*current;
	int				i;

	new_node = create_node(data);
	if (!new_node)
		return (NULL);
	if (!head || target_index == 0)
	{
		new_node->next = head;
		return (new_node);
	}
	current = head;
	i = 0;
	while (current->next && i < target_index - 1)
	{
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	current->next = new_node;
	new_node->prev = current;
	if (new_node->next)
		new_node->next->prev = new_node;
	return (head);
}
//if list is empty or target is 0
//start from head and go to target
//new node to next
//current to new
//new points back to current
//update next nodes to prev

t_stack_node	*find_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;
	int				lowest_cost;

	if (!stack)
		return (NULL);
	current = stack;
	cheapest = stack;
	lowest_cost = INT_MAX;
	while (current)
	{
		current->cheapest = 0;
		if (current->final_cost < lowest_cost)
		{
			lowest_cost = current->final_cost;
			cheapest = current;
		}
		current = current->next;
	}
	cheapest->cheapest = 1;
	return (cheapest);
}
