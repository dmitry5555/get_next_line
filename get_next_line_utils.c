/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:48:36 by dlariono          #+#    #+#             */
/*   Updated: 2023/05/07 16:48:38 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	sz;
	int		i;

	i = 0;
	sz = 0;
	while (s[i])
	{
		i++;
		sz++;
	}
	return (sz);
}

static	void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*val;
	int				i;

	i = 0;
	val = (unsigned char *)b;
	while (len > 0)
	{
		val[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	int		i;

	i = 0;
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, '\0', (count * size));
	return (mem);
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
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
