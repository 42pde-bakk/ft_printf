/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 17:03:06 by peerdb         #+#    #+#                */
/*   Updated: 2019/12/10 14:10:30 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_round(double f, t_map *map, int base)
{
	long long	result;

	result = (f - (long long)f) * ft_precpower(map, base) * base;
	if (f >= 0)
		result = (result + 5) / base;
	else
		result = (result - 5) / base;
//	if (map->typ == 'g' && result % base == 0)
//		result = result / 10;
	return (result);
}

long long	ft_divpower(long long nb)
{
	long long	result;

	result = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		result = result * 10;
	}
	return (result);
}

char		*ft_floathandler(double f, long long base, t_map *map)
{
	char		*string;
	char		*decstring;
	long long	dec;

	dec = ft_round(f, map, base);
	string = ft_itoa_base(ft_floatrect(f, map), base, map, map->typ);
	decstring = ft_itoa_base(dec, base, map, map->typ);
	string = ft_floatjoin(string, decstring, map);
	ft_floatflagger(string, 1, map);
	free(string);
	return (0);
}

void		ft_science(double f, t_map *map)
{
	char		*ret;
	long long	div;

	div = ft_divpower((long long)f);
	map->sci = (long long)f;
	f = f / div;
	ft_floathandler(f, 10, map);
	return ;
}

int			ft_exponent(long long f)
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

int			ft_g_finder(const char *s, t_map *map, va_list *args)
{
	double	f;
	int		exp;

	if (s[map->pos] == 'g')
	{
		f = va_arg(*args, double);
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
		{
			map->prec = map->prec - 1;
			map->typ = 'e';
			ft_science(f, map);
			map->pos++;
			return (1);
		}
	}
	return (0);
}

int			ft_floatfinder(const char *s, t_map *map, va_list *args)
{
	double		f;

	if (s[map->pos] == 'f' || s[map->pos] == 'F')
	{
		f = va_arg(*args, double);
		ft_floathandler(f, 10, map);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'a' || s[map->pos] == 'A')
	{
		f = va_arg(*args, double);
		ft_floathandler(f, 16, map);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'e' || s[map->pos] == 'E')
	{
		f = va_arg(*args, double);
		ft_science(f, map);
		map->pos++;
		return (1);
	}
	return (ft_g_finder(s, map, args));
}
