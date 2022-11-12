/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:47:25 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/10 15:28:31 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *rest_line)
{
	int		i;
	char	*buffer;
	char	*n_tr_line;
	char	*holder;
	
	n_tr_line = rest_line;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	while (!check_new_line(buffer))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (!i)
			return (NULL);
		buffer[BUFFER_SIZE] = 0;
		holder = ft_strjoin(n_tr_line, buffer);
		n_tr_line = holder;
		//free(holder);
	}
	return (n_tr_line);
}

static char *trim_line(char *n_tr_line, char *rest_line)
{
	int		i;
	int		j;
	char	*holder;
	char	*tr_line;
	char 	*rest_n_tr_line;
	
	i = 0;
	if (!n_tr_line)
		return (NULL);
	while (n_tr_line[i] != '\n')
		i++;
	tr_line = malloc(i + 2);
	if (!tr_line)
		return (NULL);
	tr_line[i] = '\n'; 
	tr_line[i + 1] = 0; 
	while (i-- > 0)
		tr_line[i] = n_tr_line[i];
	holder = tr_line;
	free(tr_line);
	----> rest_line = rest_of_line(n_tr_line);
	return (holder);
}

static char *rest_of_line(char *n_tr_line)
{
	int		i;
	int		j;
	int		old_i;
	int		res_len;
	char	*rest_line;
		
	i = 0;
	j = 0;
	while (n_tr_line[i])
		i++;
	old_i = i;
	
	while (n_tr_line[--i] != '\n')
	res_len = old_i - i;
	rest_line = malloc(res_len + 1);
	if (!rest_line)
		return (NULL);
	i = i + 1;
	while (n_tr_line[i])
	{
		rest_line[j] = n_tr_line[i];
		j++;
		i++;
	}
	rest_line[j] = '\0';
	return (rest_line);
	
}

char	*get_next_line(int fd)
{
	static char	*rest_line;
	char		*n_tr_line;
	char		*tr_line;
	
	n_tr_line = read_line(fd, rest_line);
	tr_line = trim_line(n_tr_line, rest_line);
	return (tr_line);
}

int main()
{
	int	fd;

	fd = open("demo.txt");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}