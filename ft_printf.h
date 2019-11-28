/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/27 22:51:17 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_map
{
	int		pos;
	int		size;
	char	*type;
	char	*param;
}				t_map;

void	ft_putchar_fd(char c, int fd, t_map *map);
void	ft_putstr_fd(char *s, int fd, t_map *map);
void	ft_putendl_fd(char *s, int fd, t_map *map);
void	ft_putnbr_fd(int n, int fd, t_map *map);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_printf(const char *, ...);

#endif
