/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_typefinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 21:32:40 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/03 17:24:53 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typefinder4(const char *s, t_map *map, va_list *args)
{
	void	*ptr;
	int		*n;
	char	*string;

	if (s[map->pos] == 'p')
	{
		ptr = va_arg(*args, void *);
		string = ft_itoa_base((unsigned long)ptr, 16, map, s[map->pos]);
		ft_putstr_fd(string, 1, map, 0);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, int*);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_typefinder3(const char *s, t_map *map, va_list *args)
{
	unsigned	o;
	int			i;
	char		*string;

	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_typefinder4(s, map, args));
}

int	ft_typefinder2(const char *s, t_map *map, va_list *args)
{
	unsigned	o;
	char		*string;

	if (s[map->pos] == 'o')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 8, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 16, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_typefinder3(s, map, args));
}

int	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char				*string;
	char				c;

	map->typ = s[map->pos];
	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		ft_putstr_fd(string, 1, map, 1);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1, map, 1);
		map->pos++;
		return (1);
	}
	return (ft_typefinder2(s, map, args));
}
