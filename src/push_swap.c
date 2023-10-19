/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:45 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/04/18 22:24:45 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit_fail(NULL, &a, &b);
	ac--;
	av++;
	argparser(&ac, av, &a);
	idx_giver(a, stack_size(a) + 1);
	sort(&a, &b);
	del_stack(&a);
	del_stack(&b);
	return (0);
}
