/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:43:08 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/16 16:13:10 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		is_new_line(char *buffer);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *ntr_line);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
#endif