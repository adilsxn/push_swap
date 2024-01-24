/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:12 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/01/24 14:56:45 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	(*src)->prev = NULL;
	*dst = *src;
	*src = tmp;
}

void	ps_pa(t_stack **a, t_stack **b, int flag)
{
	push(b, a);
	if (flag == 1)
		write(1, "pa\n", 3);
	else
		return ;
}

void	ps_pb(t_stack **a, t_stack **b, int flag)
{
	push(a, b);
	if (flag == 1)
		write(1, "pb\n", 3);
	else
		return ;
}
