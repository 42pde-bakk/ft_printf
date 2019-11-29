/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:00:44 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 16:27:56 by pde-bakk      ########   odam.nl         */
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
	map->pad = 0;
	map->ast = 0;
	map->prec = 0;
	map->l = 0;
	map->ll = 0;
	map->h = 0;
	map->hh = 0;
	map->apo = 0;
	map->hash = 0;
	map->plus = 0;
	return (map);
}

void	ft_resetmap(t_map *map)
{
	map->min = 0;
	map->spac = 0;
	map->zero = 0;
	map->pad = 0;
	map->ast = 0;
	map->prec = 0;
	map->l = 0;
	map->ll = 0;
	map->h = 0;
	map->hh = 0;
	map->apo = 0;
	map->hash = 0;
	map->plus = 0;
	return ;
}

void	ft_flagfinder(const char *s, t_map *map, va_list *args)
{
	ft_resetmap(map);
//	printf("map->pos when looking for flags =%c (%i)\n", s[map->pos], map->pos);
	if (s[map->pos] == '-')
	{
		map->min = 1;
		map->pos++;
		printf("Map->min=%d\n", map->min);
	}
	if (s[map->pos] == '+')
	{
		map->plus = 1;
		map->pos++;
		printf("map->plus=%d\n", map->plus);
	}
	if (s[map->pos] == ' ')
	{
		map->spac = 1;
		map->pos++;
		printf("Map->space=%d\n", map->spac);
	}
	if (s[map->pos] == '#')
	{
		map->hash = 1;
		map->pos++;
		printf("Map->hash=%d\n", map->hash);
	}
	if (s[map->pos] == '0')
	{
		map->zero = 1;
		map->pos++;
		printf("Map->zero=%d\n", map->zero);
	}
	while (s[map->pos] >= '0' && s[map->pos] <= '9')
	{
		map->pad = map->pad * 10 + s[map->pos] - 48;
		map->pos++;	
		printf("Map->pad=%d\n", map->pad);
	}
	if (s[map->pos] == '.')
	{
		map->pos++;
		while (s[map->pos] >= '0' && s[map->pos] <= '9')
		{
			map->prec = map->prec * 10 + s[map->pos] - 48;
			map->pos++;	
			printf("Map->prec=%d\n", map->prec);
		}
		if (s[map->pos] == '*')
		{
			map->prec = va_arg(*args, int);
			printf("Map->prec=%d\n", map->prec);
			map->pos++;
		}
	}
}

void	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char		*string;
	char		c;
	int			i;
	unsigned	o;
	void		*ptr;
	unsigned	x;

	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		ft_putstr_fd(string, 1, map);
		map->pos++;
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1, map);
		map->pos++;
	}
	if (s[map->pos] == 'd' || s[map->pos] ==  'i')
	{
		i = va_arg(*args, int);
		ft_putnbr_fd(i, 1, map);
		map->pos++;
	}
	if (s[map->pos] == 'x' || s[map->pos] ==  'X')
	{
		x = va_arg(*args, unsigned);
		string = ft_itoa_base(x, 16, s[map->pos]);
		ft_putstr_fd(string, 1, map);
		map->pos++;
	}
	if (s[map->pos] == 'o')
	{
		o = va_arg(*args, unsigned);
		string = ft_itoa_base(o, 8, 'X');
		ft_putstr_fd(string, 1, map);
		map->pos++;
	}
	if (s[map->pos] == 'p')
	{
		ptr = va_arg(*args, void *);
		string = ft_itoa_base((unsigned long)ptr, 16, 'x');
		ft_putstr_fd("0x", 1, map);
		ft_putstr_fd(string, 1, map);
		map->pos++;
	}
	if (s[map->pos] == '%')
	{
		ft_putchar_fd('%', 1, map);
		map->pos++;
	}
}

void	ft_writer(const char *s, t_map *map)
{
//	printf("%s\n", s);
	if (s[map->pos - 1] == '%')
		map->pos++;
	while (s[map->pos])
	{
		if (s[map->pos] == '%')
		{
			map->pos++;
			return ;
		}
		ft_putchar_fd(s[map->pos], 1, map);
		map->size++;
		map->pos++;
//		printf("%d\n", pos);
	}
	return ;
}

int		ft_printf(const char *s, ...)
{
	va_list	args;
	t_map	*map;

	map = ft_initmap();
	va_start(args, s);
//	printf("%p\n\n", &type);
	while (s[map->pos] != 0)
	{
		ft_writer(s, map);
//		printf("%i", map->pos);
		ft_flagfinder(s, map, &args);
		ft_typefinder(s, map, &args);
	}
	va_end(args);
	return (map->size);
}
