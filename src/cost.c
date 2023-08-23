/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:40:43 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/10 00:40:43 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	cost_giver(t_stack **a, t_stack **b)
{
	t_stack	*it_b;
	int		size_of_a;
	int		size_of_b;

	it_b = *b;
	size_of_a = stack_size(*a);
	size_of_b = stack_size(it_b);
	while (it_b)
	{
		it_b->cost_a = it_b->target_pos;
		if (it_b->cost_a > size_of_a / 2)
			it_b->cost_a = -(size_of_a - it_b->cost_a);
		it_b->cost_b = it_b->pos;
		if (it_b->cost_b > size_of_b / 2)
			it_b->cost_b = -(size_of_b - it_b->cost_b);
		it_b = it_b->next;
	}
}

void	least_costly(t_stack **a, t_stack **b)
{
	t_stack	*it;
	int		least;
	int		cost_of_a;
	int		cost_of_b;

	it = *b;
	least = INT_MAX;
	while (it)
	{
		if (ft_abs(it->cost_a) + ft_abs(it->cost_b) < ft_abs(least))
		{
			least = ft_abs(it->cost_a) + ft_abs(it->cost_b);
			cost_of_a = it->cost_a;
			cost_of_b = it->cost_b;
		}
		it = it->next;
	}
	which_move(a, b, &cost_of_a, &cost_of_b);
}

int	pos_of_min_idx(t_stack **stack)
{
	t_stack	*it;
	int		min_idx;
	int		min_pos;

	it = *stack;
	min_idx = INT_MAX;
	position_giver(*stack);
	min_pos = it->pos;
	while (it)
	{
		if (it->index < min_idx)
		{
			min_idx = it->index;
			min_pos = it->pos;
		}
		it = it->next;
	}
	return (min_pos);
}
