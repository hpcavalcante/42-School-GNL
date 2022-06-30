/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:18:53 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/30 09:15:28 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int found);
char	*ft_strjoin(char *dup_str, char *buffer);
char	*ft_return(char *print_str);
char	*ft_last_position(char *next_str);
char	*get_next_line(int fd);
char	*ft_get_str(int fd, char *read_line_str);

#endif
