/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yevkahar <yevkahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:02:52 by yevkahar          #+#    #+#             */
/*   Updated: 2025/04/02 16:13:16 by yevkahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> // INT_MAX, MIN
# include <stdbool.h> // true, false

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int					data;
	int					index;
	int					primary_cost;
	int					target_number;
	int					final_cost;
	int					cheapest;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack_node;
//nodes
t_stack_node	*lstnew(int data);
t_stack_node	*create_node(int data);
t_stack_node	*lstlast(t_stack_node *lst);
t_stack_node	*lstadd_last(t_stack_node **lst, t_stack_node *new);
t_stack_node	*find_cheapest_node(t_stack_node *stack);
t_stack_node	*insert_node(t_stack_node *head, int data, int target_index);
//error
int				check_empty(char *str);
int				check_format(char *str);
int				check_signs(char *str, int *i);
//error utils
int				is_digit(int c);
int				valid_int(char *str);
int				check_for_errors(char **av);
int				has_duplicate(char **av, int current);
int				error_exit(void);
//gnl
char			*edit_line(char *str);
char			*print_line(char *str);
char			*get_next_line(int fd);
char			*read_line(int fd, char *str);
//gnl utils
size_t			my_strlen(const char *s);
char			*my_strdup_gnl(const char *s);
char			*my_strchr(const char *s, int c);
char			*my_strjoin(char *s1, const char *s2);
char			*my_strcpy(char *s1, const char *s2);
//parsing
t_stack_node	*parse_all(char **argv);
//push
void			push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
//swap
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			swap(t_stack_node **stack);
//rotate
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
//rev rotate
void			rev_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
//sort utils
int				stack_length(t_stack_node *stack);
void			set_index(t_stack_node *stack);
int				find_min_index(t_stack_node *stack);
//sort
void			calculate_first_cost(t_stack_node *stack);
void			calculate_last_cost(t_stack_node *stack_b);
int				find_target_index(t_stack_node *stack_a, int b_index);
//sort small
void			sort_two(t_stack_node **stack);
void			sort_three(t_stack_node **stack_a);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			sort_small(t_stack_node **stack_a, t_stack_node **stack_b);
//main sort
void			print_stack(t_stack_node *stack);
void			push_to_b(t_stack_node **a, t_stack_node **b);
void			find_target_position(t_stack_node *stack_a,
					t_stack_node *stack_b);
#endif