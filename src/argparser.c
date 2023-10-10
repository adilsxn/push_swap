/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:57:08 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/04/11 20:36:08 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ps_atoi(char **str)
{
	int		sinal;
	long	res;

	res = 0;
	sinal = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
		sinal = -sinal;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (!ft_isdigit(**str))
		exit_fail("Error\n", NULL, NULL);
	while (ft_isdigit(**str))
	{
		res = res * 10 + (*(*str)++ - '0');
	}
	if (!ft_isspace(**str))
	{
		if (**str != 0 || ((res > 2147483647) || ((res > 2147483648)
					&& (sinal == 1))))
			exit_fail("Error\n", NULL, NULL);
	}
	return (res * sinal);
}

static int	ps_dupl_check(char **str, t_stack *stack)
{
	long	number;
	t_stack	*tmp;
	int		stack_sz;

	number = ps_atoi(str);
	if (!(number >= INT_MIN && number < INT_MAX))
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
