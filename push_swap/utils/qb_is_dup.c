/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qb_is_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:54:25 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 21:42:34 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	qb_is_dup(int *stack, int size)
{
	int	i;
	int	hash_table[TABLE_SIZE] = {0};
	
	i = 0;
	while (i < size) {
		int index = abs(stack[i]) % 100;
		if (hash_table[index] == stack[i]) {
			return 1;
		}
		hash_table[index] = stack[i];
		i++;
	}
	return 0;
}
