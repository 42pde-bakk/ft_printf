/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:00:44 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/27 22:51:36 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_map	*ft_initmap(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->pos = 0;
	map->type = "s";
	map->size = 0;
	return (map);
}

void	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char	*string;
	char	c;
	int		i;

	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		ft_putstr_fd(string, 1, map);
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1, map);
	}
	if (s[map->pos] == 'd' || s[map->pos] ==  'i')
	{
		i = va_arg(*args, int);
		ft_putnbr_fd(i, 1, map);
	}
}

void	ft_writer(const char *s, t_map *map)
{
//	printf("%s\n", s);
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
	char	*type;
	t_map	*map;

	map = ft_initmap();
	va_start(args, s);
	while (s[map->pos] != 0)
	{
		ft_writer(s, map);
//		printf("%i", map->pos);
		ft_typefinder(s, map, &args);
	}
	va_end(args);
	return (map->size);
}

int	main(void)
{
	char	*s;

	s = "Whateverthefuck";
	ft_printf("%s-mag je willen-%d, %i, %c\n$", s, 5, -1, 'p');
	return (0);
}
