/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 17:03:06 by peerdb         #+#    #+#                */
/*   Updated: 2019/12/09 12:47:21 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_floatjoin(char *s, char *ds, t_map *map)
{
	char	*result;
	int		i;
	int		n;
	int		length;

	i = 0;
	n = 0;
	length = ft_strlen(s) + ft_strlen(ds);
	printf("length = %i\n", length);
	if (map->prec == 0)
		length = ft_strlen(s);
	if (map->typ == 'e' || map->typ == 'E')
		length = length + 4;
	result = ft_calloc(length + 2, sizeof(char));
	if (result == 0)
		return (NULL);
	while (s && s[i])
	{
		result[i] = s[i];
		i++;
	}
	if (map->prec != 0)
	{
		result[i] = '.';
		i++;
		while (map->prec - ft_strlen(ds) > 0)
		{
			result[i] = '0';
			i++;
		}
		while (ds && ds[n])
		{
			result[i + n] = ds[n];
			n++;
		}
	}
	free(ds);
	free(s);
	return (result);
}

long long	ft_round(double f, t_map *map, int base)
{
	long long	result;

	result = (f - (long long)f) * ft_precpower(map, base) * base;
	if (f >= 0)
		result = (result + 5) / base;
	else
		result = (result - 5) / base;
	return (result);
}

void	ft_putscience(int fd, t_map *map)
{
	char	*science;
	char	*power;
	int		i;
	int 	count;

	i = 3;
	count = 0;
//	printf("test1, maptype = %c\n", map->typ);
	if (map->typ != 'e' && map->typ != 'E')
		return ;
//	printf("test2\n");
	while (map->sci >= 10)
	{
		count++;
		map->sci = map->sci / 10;
	}
	if (map->typ == 'E')
		science = "E+";
	else
		science = "e+";
	ft_putstr_fd(science, fd, map, 0);
	power = ft_itoa_base(count, 10, map, map->typ);
	if (count < 10)
		ft_putchar_fd('0', fd, map, 0);
	ft_putstr_fd(power, 1, map, 0);
}

void	ft_floatflagger(char *s, int fd, t_map *map)
{
	if (map->width > ft_strlen(s))
		map->pad = map->width - ft_strlen(s);
	if (map->typ == 'e' || map->typ == 'E')
		map->pad = map->pad - 4;
	if ((map->plus == 1 && map->nb >= 0) || map->nb < 0)
		map->pad--;
	while (map->pad > 0 && map->min == 0)
	{
		if (map->zero == 1)
			ft_putchar_fd('0', fd, map, 0);
		else
			ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
	ft_putsign_fd(fd, map);
	ft_put0x(fd, map);
	ft_putstr_fd(s, fd, map, 0);
	ft_putscience(fd, map);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
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

char	*ft_floathandler(double f, long long base, t_map *map)
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

char	*ft_science(double f, t_map *map)
{
	char		*ret;
	long long	div;
	
	div = ft_divpower((long long)f);
	map->sci = (long long)f;
	f = f / div;
	ret = ft_floathandler(f, 10, map);
	return (0);
}

int		ft_floatfinder(const char *s, t_map *map, va_list *args)
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
	return (ft_G_conversion(s, map, args));
}
