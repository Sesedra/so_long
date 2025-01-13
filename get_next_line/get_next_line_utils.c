/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:21 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/13 09:43:15 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *readed, int c)
{
	int	i;

	if (!readed)
		return (NULL);
	i = 0;
	while (readed[i])
	{
		if (readed[i] == (char)c)
			return ((char *)readed + i);
		i++;
	}
	if (readed[i] == (char)c)
		return ((char *)readed + i);
	else
		return (NULL);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			res[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
