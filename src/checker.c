/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:17:17 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/11 12:17:17 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	get_op(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "pa\n"))
		ps_pa(a, b, 0);
	else if (ft_strequ(line, "pb\n"))
		ps_pb(a, b, 0);
	else if (ft_strequ(line, "sa\n"))
		ps_sa(a, 0);
	else if (ft_strequ(line, "sb\n"))
		ps_sb(b, 0);
	else if (ft_strequ(line, "ss\n"))
		ps_ss(a, b, 0);
	else if (ft_strequ(line, "ra\n"))
		ps_ra(a, 0);
	else if (ft_strequ(line, "rb\n"))
		ps_rb(b, 0);
	else if (ft_strequ(line, "rr\n"))
		ps_rr(a, b, 0);
	else if (ft_strequ(line, "rra\n"))
		ps_rra(a, 0);
	else if (ft_strequ(line, "rrb\n"))
		ps_rrb(b, 0);
	else if (ft_strequ(line, "rrr\n"))
		ps_rrr(a, b, 0);
	else
		exit_fail("Error\n", a, b);
	free(line);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	if (ac < 2)
		exit(1);
	ac--;
	av++;
	b = NULL;
	a = NULL;
	argparser(&ac, av, &a);
	instruction = get_next_line(0);
	while (instruction)
	{
		get_op(instruction, &a, &b);
		instruction = get_next_line(0);
	}
	free(instruction);
	if (issorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	del_stack(&a);
	del_stack(&b);
	return (0);
}
