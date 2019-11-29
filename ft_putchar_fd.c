/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/30 00:25:37 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar_fd(char c, int fd, t_map *map, int check)
{
	if (check == 1 && map->pad > 0)
	{
		map->pad--;
		ft_flagfiller(fd, map);
	}
	write(fd, &c, 1);
	map->size++;
	while (check == 1 && map->min == 1 && map->pad > 0)
	{
		write(1, " ", 1);
		map->pad--;
	}
}

void	ft_putstr_fd(char *s, int fd, t_map *map)
{
	int	i;
//	int length;
//	int fill;

	i = 0;
	if (ft_strlen(s) > map->prec && map->prec > -1)
		map->pad = map->pad - map->prec;
	else
		map->pad = map->pad - ft_strlen(s);
	if (map->min == 0)
		ft_flagfiller(fd, map);
//	printf("fill = %d\n", fill);
	while (s[i] && map->prec == -1)
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
	}
	while (s[i] && map->prec > 0)
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
		map->prec--;
	}
//	printf("padding left over = %d, fill = %d\n", map->pad, fill);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', 1, map, 0);
		map->pad--;
	}
}

void	ft_putnbr_fd(int n, int fd, t_map *map)
{
	if (map->plus == 1)
	{
		ft_putchar_fd('+', fd, map, 0);
		map->plus = 0;
}
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd, map, 0);
		ft_putchar_fd('2', fd, map, 0);
		ft_putnbr_fd(147483648, fd, map);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, map, 0);
		ft_putnbr_fd(-n, fd, map);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, map);
		ft_putnbr_fd(n % 10, fd, map);
	}
	else
		ft_putchar_fd(n + 48, fd, map, 0);
}
