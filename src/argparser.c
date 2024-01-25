/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:57:08 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/01/24 14:53:18 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ps_atoll(char **str, int *number)
{
	int					sinal;
	unsigned long long	res;
	unsigned long long	max;

	res = 0;
	sinal = 1;
	max = INT_MAX;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
		sinal = -sinal;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (!ft_isdigit(**str))
		return (true);
	while (ft_isdigit(**str))
		res = res * 10 + (*(*str)++ - '0');
	if (!ft_isspace(**str))
		if (**str != 0)
			return (true);
	if (res > max)
		return (true);
	*number = (int)(res * sinal);
	return (false);
}

static int	ps_dupl_check(char **str, t_stack *stack)
{
	int		number;
	t_stack	*tmp;
	int		stack_sz;

	if (ps_atoll(str, &number) == true)
		exit_fail("Error\n", &stack, NULL);
	stack_sz = stack_size(stack);
	if (stack_sz > 0)
	{
		tmp = stack;
		while (tmp)
		{
			if (number == tmp->data)
				exit_fail("Error\n", &stack, NULL);
			tmp = tmp->next;
		}
	}
	return (number);
}

static void	ps_conv_arg(char *av, t_stack **stack)
{
	int		i;
	int		w;
	t_stack	*tmp;

	i = 0;
	w = ft_wordcount(av, ' ');
	tmp = NULL;
	if (!ft_strlen(av) || !w)
		exit_fail("Error\n", stack, NULL);
	while (i < w && *av)
	{
		tmp = new_stack(ps_dupl_check(&av, *stack));
		stack_append(stack, tmp);
		i++;
	}
}

void	argparser(int *ac, char **av, t_stack **stack)
{
	while (*ac)
	{
		ps_conv_arg(*av, stack);
		av++;
		(*ac)--;
	}
}
