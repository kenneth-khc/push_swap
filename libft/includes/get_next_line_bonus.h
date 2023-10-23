/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:21:03 by kecheong          #+#    #+#             */
/*   Updated: 2023/08/11 20:28:10 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	read_file(int fd, char **line, char **buffer);
void	extract_line(char **buffer, char **line, ssize_t *bytes);

void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strjoin(char *str1, char const *str2);
char	*gnl_substr(char const *str, unsigned int index, size_t len);

#endif