/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:35:24 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/08 22:35:24 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_2ndlast_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*new_stack(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = value;
	node->index = 0;
	node->pos = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	stack_append(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->prev = get_last_stack(*stack);
	get_last_stack(*stack)->next = new;
}
