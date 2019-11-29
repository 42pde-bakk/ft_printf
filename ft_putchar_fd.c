/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 16:21:15 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int		ft_flagfiller(int length, int fd, t_map *map)
{
	int	fill;

	fill = map->pad - length;
	while (fill > 0 && (map->spac == 1 || map->zero == 1))
	{
		if (map->spac == 1)
			ft_putchar_fd(' ', 1, map);
		if (map->zero == 1)
			ft_putchar_fd('0', 1, map);
		fill--;
	}
	return (fill);
}

void	ft_putchar_fd(char c, int fd, t_map *map)
{
	write(fd, &c, 1);
	map->size++;
}

void	ft_putstr_fd(char *s, int fd, t_map *map)
{
	int	i;
	int length;

	i = 0;
	length = ft_strlen(s);
	length = ft_flagfiller(length, fd, map);
	while (s[i] && map->prec > 0)
	{
		write(fd, &s[i], 1);
		i++;
		map->size++;
		map->prec--;
	}
	while (map->min == 1 && length > 0)
	{
		ft_putchar_fd(' ', 1, map);
		length--;
	}
}

void	ft_putnbr_fd(int n, int fd, t_map *map)
{
	if (map->plus == 1)
	{
		ft_putchar_fd('+', fd, map);
		map->plus = 0;
}
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd, map);
		ft_putchar_fd('2', fd, map);
		ft_putnbr_fd(147483648, fd, map);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, map);
		ft_putnbr_fd(-n, fd, map);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, map);
		ft_putnbr_fd(n % 10, fd, map);
	}
	else
		ft_putchar_fd(n + 48, fd, map);
}
