/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 23:52:28 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_map
{
	int		pos;
	int		size;
	int		min;
	int		spac;
	int		zero;
	int		pad;
	int		ast;
	int		prec;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		apo;
	int		hash;
	int		plus;
}				t_map;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);

void			ft_putchar_fd(char c, int fd, t_map *map, int check);
void			ft_putstr_fd(char *s, int fd, t_map *map);
void			ft_putendl_fd(char *s, int fd, t_map *map);
void			ft_putnbr_fd(int n, int fd, t_map *map);

char			*ft_itoa_base(unsigned long nb, unsigned long base, char c);

void			ft_flagfinder(const char *s, t_map *map, va_list *args);
void			ft_flagfiller(int fd, t_map *map);

t_map			*ft_initmap(void);
t_map			*ft_resetmap(t_map *map);

void			ft_typefinder(const char *s, t_map *map, va_list *args);
void			ft_writer(const char *s, t_map *map);
int				ft_printf(const char *s, ...);

#endif
