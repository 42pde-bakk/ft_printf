/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/03 14:31:36 by pde-bakk      ########   odam.nl         */
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
	int				pos;
	int				size;
	int				min;
	int				spac;
	int				zero;
	int				width;
	int				pad;
	int				prec;
	int				pfill;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				hash;
	int				plus;
	unsigned long	nb;
}				t_map;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);

void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);

void			ft_putchar_fd(char c, int fd, t_map *map, int check);
void			ft_putstr_fd(char *s, int fd, t_map *map, int check);
void			ft_putendl_fd(char *s, int fd, t_map *map);
void			ft_nbrputter_fd(char *s, int fd, t_map *map);

char			*ft_itoa_base(long long nb, long long base, t_map *map, char c);

void			ft_flagfinder(const char *s, t_map *map, va_list *args);
void			ft_secondflagfinder(const char *s, t_map *map, va_list *args);
void			ft_flagfiller(int fd, t_map *map, char *s);

t_map			*ft_initmap(void);
t_map			*ft_resetmap(t_map *map);

int				ft_typefinder(const char *s, t_map *map, va_list *args);
int				ft_typefinder2(const char *s, t_map *map, va_list *args);
int				ft_typefinder3(const char *s, t_map *map, va_list *args);
int				ft_typefinder4(const char *s, t_map *map, va_list *args);

int				ft_longfinder(const char *s, t_map *map, va_list *args);
int				ft_shortfinder(const char *s, t_map *map, va_list *args);
int				ft_longlongfinder(const char *s, t_map *map, va_list *args);
int				ft_shortshortfinder(const char *s, t_map *map, va_list *args);

void			ft_writer(const char *s, t_map *map);
int				ft_printf(const char *s, ...);

#endif
