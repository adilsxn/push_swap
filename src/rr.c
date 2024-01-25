/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:10:22 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/04/07 17:10:22 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	tail = get_last_stack(*stack);
	second_last = get_2ndlast_stack(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	second_last->next = NULL;
}

void	ps_rra(t_stack **a, int flag)
{
	rev_rotate(a);
	if (flag == 1)
		write(1, "rra\n", 4);
	else
		return ;
}

void	ps_rrb(t_stack **b, int flag)
{
	rev_rotate(b);
	if (flag == 1)
		write(1, "rrb\n", 4);
	else
		return ;
}

void	ps_rrr(t_stack **a, t_stack **b, int flag)
{
	rev_rotate(a);
	rev_rotate(b);
	if (flag == 1)
		write(1, "rrr\n", 4);
	else
		return ;
}
