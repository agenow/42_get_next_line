/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:51:24 by agenow            #+#    #+#             */
/*   Updated: 2024/06/04 16:08:49 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_newline(char *s);
char	*ft_strjoin(char *s, char *buf);
char	*ft_extract_line(const char *s);
char	*ft_trim_buffer(char *s);
char	*get_next_line(int fd);

#endif