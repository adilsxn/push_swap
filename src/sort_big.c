/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:16:12 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/10 16:16:12 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_till_3(t_stack **a, t_stack **b, int size_of_a)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < size_of_a && pushed < size_of_a / 2)
	{
		if ((*a)->index <= size_of_a / 2)
		{
			ps_pb(a, b, 1);
			pushed++;
		}
		else
			ps_ra(a, 1);
		i++;
	}
	while (size_of_a - pushed > 3)
	{
		ps_pb(a, b, 1);
		pushed++;
	}
}

static void	shift_stack(t_stack **stack, int size_of_stack)
{
	int	lowest_pos;

	lowest_pos = pos_of_min_idx(stack);
	if (lowest_pos > size_of_stack / 2)
	{
		while (lowest_pos < size_of_stack)
		{
			ps_rra(stack, 1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ps_ra(stack, 1);
			lowest_pos--;
		}
	}
}

static void	sort_big(t_stack **a, t_stack **b)
{
	push_till_3(a, b, stack_size(*a));
	sort_three(a);
	while (*b)
	{
		target_pos_giver(a, b);
		cost_giver(a, b);
		least_costly(a, b);
	}
	if (!issorted(*a))
		shift_stack(a, stack_size(*a));
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 1 || issorted(*a))
		return ;
	else if (stack_size(*a) <= 5)
		sort_small(a, b);
	else if (stack_size(*a) > 5)
		sort_big(a, b);
}
