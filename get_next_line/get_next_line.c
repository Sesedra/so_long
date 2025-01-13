/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:30:58 by srabeman          #+#    #+#             */
/*   Updated: 2024/06/13 16:22:12 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_all(char *buffer, char *readed)
{
	free(buffer);
	free(readed);
	return (NULL);
}

static int	ft_get_newline_index(char *text)
{
	int	i;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	return (i);
}

static char	*ft_extract_line(char *readed)
{
	char	*line;
	int		newln_i;

	if (!readed || *readed == '\0')
		return (NULL);
	newln_i = ft_get_newline_index(readed);
	line = (char *)malloc(sizeof(char) * (newln_i + 1));
	if (!line)
		return (NULL);
	newln_i = 0;
	while (readed[newln_i] && readed[newln_i] != '\n')
	{
		line[newln_i] = readed[newln_i];
		newln_i++;
	}
	if (readed[newln_i] == '\n')
		line[newln_i++] = '\n';
	line[newln_i] = '\0';
	return (line);
}

static char	*ft_update_remain_text(char *rmn_txt)
{
	char	*new_txt;
	int		nw_ln_i;
	int		new_len;

	if (!rmn_txt)
		return (NULL);
	nw_ln_i = 0;
	if (rmn_txt[nw_ln_i] == '\0')
	{
		free(rmn_txt);
		return (NULL);
	}
	nw_ln_i = ft_get_newline_index(rmn_txt);
	new_txt = (char *)malloc(sizeof(char) * (ft_strlen(rmn_txt) - nw_ln_i + 1));
	if (!new_txt)
		return (NULL);
	new_len = 0;
	while (rmn_txt[nw_ln_i])
		new_txt[new_len++] = rmn_txt[nw_ln_i++];
	new_txt[new_len] = '\0';
	free(rmn_txt);
	return (new_txt);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*buffer;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(readed, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free_all(buffer, readed));
		if (byte_read == 0)
			break ;
		*(buffer + byte_read) = '\0';
		readed = ft_strjoin(readed, buffer);
	}
	free(buffer);
	buffer = ft_extract_line(readed);
	readed = ft_update_remain_text(readed);
	return (buffer);
}
