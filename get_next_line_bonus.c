/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:08:55 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/30 09:34:33 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_str(int fd, char *read_line_str)
{
	int		read_byte;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_byte = 1;
	while (!ft_strchr(read_line_str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		read_line_str = ft_strjoin(read_line_str, buffer);
	}
	free(buffer);
	return (read_line_str);
}

char	*get_next_line(int fd)
{
	static char	*get_str[1024];
	char		*the_line;

	the_line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	get_str[fd] = ft_get_str(fd, get_str[fd]);
	if (!get_str[fd])
		return (NULL);
	the_line = ft_return(get_str[fd]);
	get_str[fd] = ft_last_position(get_str[fd]);
	if (the_line[0] == '\0')
	{
		free(get_str[fd]);
		free(the_line);
		return (NULL);
	}
	return (the_line);
}
