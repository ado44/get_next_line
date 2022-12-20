/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:45:03 by amarna            #+#    #+#             */
/*   Updated: 2022/10/22 13:24:05 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(char *s);
int		is_newline(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *reserve, char *buf);
char	*free_str_from_stat(char *line);
char	*get_returned_line(char *line);
char	*get_next_line(int fd);

#endif