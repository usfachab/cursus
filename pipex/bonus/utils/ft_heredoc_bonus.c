/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:57:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 20:20:29 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

void	ft_heredoc(int fd, char *limiter)
{
	char	*str;

	while (1)
	{
		if (write(1, "pipe heredoc> ", 14) < 0)
			err_msg("Error: failed to write in htdox");
		str = get_next_line(STDIN_FILENO);
		if (!str)
			exit(1);
		if (is_heredoc(str, limiter, -1))
			break ;
		else if (write(fd, str, ft_strlen(str)) < 0)
			err_msg("Error: failed to write in htdox");
	}
}
