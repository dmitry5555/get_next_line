/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrylarionov <dmitrylarionov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:09:41 by dmitrylario       #+#    #+#             */
/*   Updated: 2023/04/30 20:22:51 by dmitrylario      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	l = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
	{
		return (ft_strlen(src) + dstsize);
	}
	while (src[i] && l < dstsize - 1)
	{
		dst[l] = src[i];
		l++;
		i++;
	}
	dst[l] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s1 == NULL)
		return (s2);
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstring == NULL)
		return (NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		newstring[i + n] = s2[n];
		n++;
	}
	newstring[i + n] = '\0';
	free(s1);
	free(s2);
	return (newstring);
}