/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:00 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 20:36:10 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strleng(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i++])
		;
	return (i - 1);
}

int	ft_strchrg(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin_andfree_s1(char *s1, const char *s2)
{
	char	*ptr;
	size_t	size;
	int		i;
	int		j;

	size = ft_strleng(s1) + ft_strleng(s2);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		while (s1[i])
			ptr[j++] = s1[i++];
	}
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
			ptr[j++] = s2[i++];
	}
	free(s1);
	ptr[j] = 0;
	return (ptr);
}

size_t	ft_strlcpyg(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	length = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[length] != '\0')
		length++;
	i = 0;
	if (dstsize == 0)
		return (length);
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (length);
}

int	ft_check_endfile(char *str_line, int control)
{
	if (control == 0 || control < 0)
	{
		free(str_line);
		return (1);
	}
	return (0);
}
