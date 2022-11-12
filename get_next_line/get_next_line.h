/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:43:08 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/10 14:58:24 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*get_next_line(int fd);
int		check_new_line(char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
static char *rest_of_line(char *n_tr_line);
#endif