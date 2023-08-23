/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:50:09 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/10 00:50:09 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ps_rr(a, b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	rrr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		ps_rrr(a, b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	ra_rra(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ps_ra(a, 1);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			ps_rra(a, 1);
			(*cost_a)++;
		}
	}
}

static void	rb_rrb(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			ps_rb(b, 1);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			ps_rrb(b, 1);
			(*cost_b)++;
		}
	}
}

void	which_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	if (*cost_a > 0 && *cost_b > 0)
		rr_both(a, b, cost_a, cost_b);
	else if (*cost_a < 0 && *cost_b < 0)
		rrr_both(a, b, cost_a, cost_b);
	ra_rra(a, cost_a);
	rb_rrb(b, cost_b);
	ps_pa(a, b, 1);
}
