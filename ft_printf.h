/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/08 17:49:48 by pde-bakk      ########   odam.nl         */
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
	char			typ;
	int				min;
	int				spac;
	int				zero;
	int				width;
	int				pad;
	int				prec;
	int				pfill;
	int				bon;
	int				hash;
	int				apos;
	int				plus;
	long long		nb;
	long long		sci;
}				t_map;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);

int				ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd, t_map *map, int check);
void			ft_putstr_fd(char *s, int fd, t_map *map, int check);
void			ft_nbrprinter_fd(char *s, int fd, t_map *map);
void			ft_putsign_fd(int fd, t_map *map);

void			ft_put0x(int fd, t_map *map);
void			ft_nbrflagger_fd(char *s, int fd, t_map *map);
void			ft_lastputstuff(char *s, int fd, t_map *map);
void			ft_nbrputter_fd(char *s, int fd, t_map *map);

int				ft_amount(long long nb, long long base, t_map *map);
int				ft_absolutely(long long nb);
char			*ft_itoa_base(long long nb, long long base, t_map *map, char c);
int				ft_precpower(t_map *map, int base);
long long int	ft_floatrect(double f, t_map *map);

void			ft_flagfinder(const char *s, t_map *map, va_list *args);
void			ft_secondflagfinder(const char *s, t_map *map, va_list *args);
void			ft_flagfiller(int fd, t_map *map, char *s);

t_map			*ft_initmap(void);
t_map			*ft_resetmap(t_map *map);

int				ft_typefinder(const char *s, t_map *map, va_list *args);
int				ft_typefinder2(const char *s, t_map *map, va_list *args);
int				ft_typefinder3(const char *s, t_map *map, va_list *args);
int				ft_typefinder4(const char *s, t_map *map, va_list *args);

int				ft_thebigshort(const char *s, t_map *map, va_list *args);
int				ft_longfinder(const char *s, t_map *map, va_list *args);
int				ft_shortfinder(const char *s, t_map *map, va_list *args);
int				ft_longlongfinder(const char *s, t_map *map, va_list *args);
int				ft_shortshortfinder(const char *s, t_map *map, va_list *args);

int				ft_floatfinder(const char *s, t_map *map, va_list *args);
void			ft_floatflagger(char *s, int fd, t_map *map);
long long		ft_round(double f, t_map *map, int base);
char			*ft_floatjoin(char *s, char *ds, t_map *map);

void			ft_writer(const char *s, t_map *map);
int				ft_printf(const char *s, ...);

#endif
