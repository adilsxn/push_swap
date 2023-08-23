/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:10:42 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/04/08 16:15:35 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_last_stack(*stack);
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
}

void	ps_ra(t_stack **a, int flag)
{
	rotate(a);
	if (flag == 1)
		write(1, "ra\n", 3);
	else
		return ;
}

void	ps_rb(t_stack **b, int flag)
{
	rotate(b);
	if (flag == 1)
		write(1, "rb\n", 3);
	else
		return ;
}

void	ps_rr(t_stack **a, t_stack **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag == 1)
		write(1, "rr\n", 3);
	else
		return ;
}
