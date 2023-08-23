/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:54:43 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/09 23:54:43 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_giver(t_stack *stack)
{
	t_stack	*it;
	int		iter;

	it = stack;
	iter = 0;
	while (it)
	{
		it->pos = iter;
		it = it->next;
		iter++;
	}
}

static int	target_giver(t_stack **a, int idx_of_b, int target_idx,
		int target_pos)
{
	t_stack	*it_a;

	it_a = *a;
	while (it_a)
	{
		if (it_a->index > idx_of_b && it_a->index < target_idx)
		{
			target_idx = it_a->index;
			target_pos = it_a->pos;
		}
		it_a = it_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	it_a = *a;
	while (it_a)
	{
		if (it_a->index < target_idx)
		{
			target_idx = it_a->index;
			target_pos = it_a->pos;
		}
		it_a = it_a->next;
	}
	return (target_pos);
}

void	target_pos_giver(t_stack **a, t_stack **b)
{
	t_stack	*it_b;
	int		tmp_pos;

	it_b = *b;
	tmp_pos = 0;
	position_giver(*a);
	position_giver(*b);
	while (it_b)
	{
		tmp_pos = target_giver(a, it_b->index, INT_MAX, tmp_pos);
		it_b->target_pos = tmp_pos;
		it_b = it_b->next;
	}
}
