/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:00:42 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/08 12:00:42 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx_giver(t_stack *stack, int stack_sz)
{
	t_stack	*it;
	t_stack	*lowest;
	int		val;

	while (--stack_sz > 0)
	{
		it = stack;
		lowest = NULL;
		val = INT_MIN;
		while (it)
		{
			if (it->data == INT_MIN && it->index == 0)
				it->index = 1;
			if (it->data > val && it->index == 0)
			{
				val = it->data;
				lowest = it;
				it = stack;
			}
			else
				it = it->next;
		}
		if (lowest != NULL)
			lowest->index = stack_sz;
	}
}

void	del_stack(t_stack **stack)
{
	t_stack	*it;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		it = (*stack)->next;
		free(*stack);
		*stack = it;
	}
	*stack = NULL;
}

void	exit_fail(char *s, t_stack **a, t_stack **b)
{
	ft_putstr_fd(s, 2);
	del_stack(a);
	del_stack(b);
	exit(1);
}

int	issorted(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
