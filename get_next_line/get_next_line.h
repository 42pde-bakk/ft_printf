/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 12:21:37 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/06/11 17:17:46 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strdup_gnl(const char *s1, int n, int startpos);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoiner_gnl(char *s1, char *s2, int ret);
void	ft_bzero_gnl(char *s, int n);
int		get_next_line(int fd, char **line);

#endif
