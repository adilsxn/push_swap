/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:14:49 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/04/23 17:18:41 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// Structures declarations
typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Error messages
void				exit_fail(char *s, t_stack **a, t_stack **b);

// Stack creations
t_stack				*get_last_stack(t_stack *stack);
t_stack				*get_2ndlast_stack(t_stack *stack);
t_stack				*new_stack(int value);
int					stack_size(t_stack *stack);
void				stack_append(t_stack **stack, t_stack *new);
void				argparser(int *ac, char **av, t_stack **stack);
void				idx_giver(t_stack *stack, int stack_sz);
void				del_stack(t_stack **stack);

// Push_swap operations
void				ps_pa(t_stack **a, t_stack **b, int flag);
void				ps_pb(t_stack **a, t_stack **b, int flag);
void				ps_ra(t_stack **a, int flag);
void				ps_rb(t_stack **b, int flag);
void				ps_rr(t_stack **a, t_stack **b, int flag);
void				ps_rra(t_stack **a, int flag);
void				ps_rrb(t_stack **b, int flag);
void				ps_rrr(t_stack **a, t_stack **b, int flag);
void				ps_sa(t_stack **a, int flag);
void				ps_sb(t_stack **b, int flag);
void				ps_ss(t_stack **a, t_stack **b, int flag);
// Algorithm auxs
void				position_giver(t_stack *stack);
void				cost_giver(t_stack **a, t_stack **b);
void				least_costly(t_stack **a, t_stack **b);
int					pos_of_min_idx(t_stack **stack);
void				target_pos_giver(t_stack **a, t_stack **b);
void				which_move(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);

// Algorithm
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_four(t_stack **stack_a, t_stack **stack_b);

void				sort_three(t_stack **stack);
void				sort_small(t_stack **a, t_stack **b);
int					issorted(t_stack *head);
void				sort(t_stack **a, t_stack **b);

#endif
