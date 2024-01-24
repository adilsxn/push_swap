/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:09:58 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/01/24 14:56:59 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !(stack->next))
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	ps_sa(t_stack **a, int flag)
{
	swap(*a);
	if (flag == 1)
		write(1, "sa\n", 3);
	else
		return ;
}

void	ps_sb(t_stack **b, int flag)
{
	swap(*b);
	if (flag == 1)
		write(1, "sb\n", 3);
	else
		return ;
}

void	ps_ss(t_stack **a, t_stack **b, int flag)
{
	swap(*a);
	swap(*b);
	if (flag == 1)
		write(1, "ss\n", 3);
	else
		return ;
}
