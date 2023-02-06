/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:42:20 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 21:35:14 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TABLE_SIZE 100
 
// <--- func --->
int		ft_atoi(const char	*str);
int		ft_isdigit(char c);
size_t	ft_strlen(const char *s);

// <--- utils - qb_stderr.c --->
void	qb_stderr(char *msg);

int		qb_is_dup(int *stack, int size);

#endif