/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gconversion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 12:30:43 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/09 12:47:38 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_G_handler(double f, long long base, t_map *map)
{
	char		*string;
	char		*decstring;
	long long	dec;

	dec = ft_round(f, map, base);
//	printf("dec = %lli\n", dec);
	string = ft_itoa_base(ft_floatrect(f, map), base, map, map->typ);
	decstring = ft_itoa_base(dec, base, map, map->typ);
//	printf("join=%s.%s\n", string, decstring);
	string = ft_floatjoin(string, decstring, map);
//	printf("after floatjoin = %s\n", string);
	return (string);
}

char	*ft_G_science(double f, t_map *map)
{
	char		*ret;
	long long	div;
	
	div = ft_divpower((long long)f);
	map->sci = (long long)f;
	f = f / div;
	ret = ft_G_handler(f, 10, map);
	return (ret);
}

int	ft_G_conversion(const char *s, t_map *map, va_list *args)
{
	double	f;
	char	*flo;
	char	*scn;

	if (s[map->pos] == 'g')
	{
		f = va_arg(*args, double);
//		printf("double = %f\n", f);
		flo = ft_G_handler(f, 10, map);
		printf("float notation = %s\n", flo);
		scn = ft_G_science(f, map);
		printf("science notation = %s\n", scn);
		if (ft_strlen(scn) < ft_strlen(flo))
		{
			map->typ = 'e';
			ft_floatflagger(scn, 1, map);
//			printf("map->typ = %c\n", map->typ);
		}
		else
		{
			map->typ = 'f';
			ft_floatflagger(flo, 1, map);
//			printf("f -> map->typ = %c\n", map->typ);
		}
		free(flo);
		free(scn);
		map->pos++;
		return (1);
	}
	return (0);
}
