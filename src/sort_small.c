/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:35:50 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/05 11:35:50 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_stack *stack)
{
	t_stack	*it;
	int		max;

	it = stack;
	max = 0;
	while (it)
	{
		if (it->data > max)
			max = it->data;
		it = it->next;
	}
	return (max);
}

void	sort_three(t_stack **stack)
{
	int	max;

	max = get_max(*stack);
	if (max == (*stack)->data)
		ps_ra(stack, 1);
	else if (max == (*stack)->next->data)
		ps_rra(stack, 1);
	if ((*stack)->data > (*stack)->next->data)
		ps_sa(stack, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index >= 2)
			ps_ra(stack_a, 1);
		if ((*stack_a)->index < 2)
			ps_pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	while (*stack_b)
		ps_pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
			ps_ra(stack_a, 1);
		if ((*stack_a)->index <= 2)
			ps_pb(stack_a, stack_b, 1);
	}
	if (issorted(*stack_b))
		ps_sb(stack_b, 1);
	sort_three(stack_a);
	while (*stack_b)
		ps_pa(stack_a, stack_b, 1);
}

void	sort_small(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		ps_sa(a, 1);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
		sort_five(a, b);
}
