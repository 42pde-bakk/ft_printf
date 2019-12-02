/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:00:44 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 21:17:13 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_map	*ft_initmap(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->pos = 0;
	map->size = 0;
	map->min = 0;
	map->spac = 0;
	map->zero = 0;
	map->width = 0;
	map->pad = 0;
	map->ast = 0;
	map->prec = -1;
	map->pfill = 0;
	map->l = 0;
	map->ll = 0;
	map->h = 0;
	map->hh = 0;
	map->apo = 0;
	map->hash = 0;
	map->plus = 0;
	map->nb = 0;
	return (map);
}

t_map	*ft_resetmap(t_map *map)
{
	map->min = 0;
	map->spac = 0;
	map->zero = 0;
	map->width = 0;
	map->pad = 0;
	map->ast = 0;
	map->prec = -1;
	map->pfill = 0;
	map->l = 0;
	map->ll = 0;
	map->h = 0;
	map->hh = 0;
	map->apo = 0;
	map->hash = 0;
	map->plus = 0;
	map->nb = 0;
	return (map);
}

void	ft_typefinder3(const char *s, t_map *map, va_list *args)
{
	void				*ptr;
	int					*n;
	double				f;

	if (s[map->pos] == 'p')
	{
		ptr = va_arg(*args, void *);
		string = ft_itoa_base((unsigned long)ptr, 16, map, s[map->pos]);
		ft_putstr_fd(string, 1, map, 0);
		free(string);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, long long int*);
		*n = map->size;
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'f')
	{
		f = va_arg(*args, long double);
		
	}
}

void	ft_typefinder2(const char *s, t_map *map, va_list *args)
{
	if (s[map->pos] == 'u')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'x' || s[map->pos] ==  'X')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 16, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'o')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 8, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
}

void	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char				*string;
	char				c;
	long long			i;
	unsigned long long	o;

//	map->type = s[map->pos];
	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		ft_putstr_fd(string, 1, map, 1);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1, map, 1);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'd' || s[map->pos] ==  'i')
	{
		i = va_arg(*args, long long int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
}

void	ft_writer(const char *s, t_map *map)
{
	while (s[map->pos])
	{
		if (s[map->pos] == '%' && s[map->pos + 1] == '%')
			{
				ft_putchar_fd(s[map->pos], 1, map, 0);
				map->pos = map->pos + 2;
			}
		if (s[map->pos] == '%')
		{
			map->pos++;
			return ;
		}
		ft_putchar_fd(s[map->pos], 1, map, 0);
		map->pos++;
	}
	return ;
}

int		ft_printf(const char *s, ...)
{
	va_list	args;
	t_map	*map;

	map = ft_initmap();
	va_start(args, s);
	while (s[map->pos])
	{
		ft_writer(s, map);
		ft_flagfinder(s, map, &args);
		ft_typefinder(s, map, &args);
		map = ft_resetmap(map);
	}
	va_end(args);
	return (map->size);
}
