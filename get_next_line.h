/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrylarionov <dmitrylarionov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:07:14 by dmitrylario       #+#    #+#             */
/*   Updated: 2023/05/01 15:53:06 by dmitrylario      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1000
# endif

// typedef struct	s_list
// {
// 	void	*content;
// 	struct s_list	*next;
// }	t_list;

size_t	ft_strlen(const char *a);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
