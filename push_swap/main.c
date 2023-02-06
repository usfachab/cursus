/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:41:26 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 21:31:26 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	*init_stack_a(int argc, char **argv)
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				qb_stderr("Error");
			j++;
		}
	}
	i = 0;
	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	while (++i < argc)
		stack[i - 1] = ft_atoi(argv[i]);
	return (stack);
}

int	main(int argc, char *argv[])
{
	int	*stack_a;

	stack_a = init_stack_a(argc, argv);
	if (qb_is_dup(stack_a, argc - 1))
		qb_stderr("Fuck");
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", stack_a[i]);
	return (0);
}

