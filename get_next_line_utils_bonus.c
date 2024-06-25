/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:51:00 by agenow            #+#    #+#             */
/*   Updated: 2024/06/04 16:20:56 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_newline(char *s)
{
	if (!s)
		return (1);
	while (*s)
		if (*s++ == '\n')
			return (0);
	return (1);
}

char	*ft_strjoin(char *s, char *buf)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = 0;
	if (!s)
	{
		s = malloc(sizeof(char) * 1);
		s[0] = '\0';
	}
	join = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buf)) + 1));
	if (!join)
	{
		free(s);
		return (NULL);
	}
	while (s[++i])
		join[i] = s[i];
	while (buf[j])
		join[i++] = buf[j++];
	join[i] = '\0';
	free(s);
	return (join);
}

char	*ft_extract_line(const char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_trim_buffer(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!line)
	{
		free(s);
		return (NULL);
	}
	i = i + 1;
	while (s[i])
		line[j++] = s[i++];
	line[j] = '\0';
	free(s);
	return (line);
}
