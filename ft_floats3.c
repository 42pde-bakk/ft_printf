/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:16:15 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/10 16:00:50 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_floatingpointexception(double f, t_map *map)
{
	if (f != f)
	{
		ft_putstr_flags("nan", 1, map, 1);
		map->pos++;
		return (1);
	}
	else if (f < (__DBL_MAX__ * -1))
	{
		ft_putstr_flags("-inf", 1, map, 1);
		map->pos++;
		return (1);
	}
	else if (f > __DBL_MAX__)
	{
		ft_putstr_flags("inf", 1, map, 1);
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_exponent(long long f)
{
	int	exp;

	exp = 0;
	while (f > 10)
	{
		f = f / 10;
		exp++;
	}
	return (exp);
}

int	ft_g2_finder(double f, t_map *map)
{
	map->prec = map->prec - 1;
	map->typ = 'e';
	ft_science(f, map);
	map->pos++;
	return (1);
}

int	ft_g_finder(const char *s, t_map *map, double f)
{
//	double	f;
	int		exp;

	if (s[map->pos] == 'g' || s[map->pos] == 'G')
	{
//		f = va_arg(*args, double);
		if (map->prec == -1)
			map->prec = 6;
		if (map->prec == 0)
			map->prec = 1;
		exp = ft_exponent((long long)f);
		if (map->prec > exp)
		{
			map->prec = map->prec - (exp + 1);
			ft_floathandler(f, 10, map);
			map->pos++;
			return (1);
		}
		else
			return (ft_g2_finder(f, map));
	}
	return (0);
}
