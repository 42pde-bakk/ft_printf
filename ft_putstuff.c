/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstuff.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/04 18:44:06 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
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
	if (check == 1 && map->width > 0)
	{
		map->width--;
		while (map->min == 0 && map->width > 0)
		{
			if (map->zero == 0)
				ft_putchar_fd(' ', fd, map, 0);
			else
				ft_putchar_fd('0', fd, map, 0);
			map->width--;
		}
	}
	write(fd, &c, 1);
	map->size++;
	while (check == 1 && map->min == 1 && map->width > 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->width--;
	}
}

int		ft_putstr_fd(char *s, int fd, t_map *map, int check)
{
	int	i;

	i = 0;
	if (check == 1)
		ft_flagfiller(fd, map, s);
	while (s[i] && (map->prec == -1 || check == 0))
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
	}
	if (check == 0)
		return (0);
	while (s[i] && map->prec > 0)
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
		map->prec--;
	}
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', 1, map, 0);
		map->pad--;
	}
	return (0);
}

void	ft_nbrprinter_fd(char *s, int fd, t_map *map)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (map->nb == 0 && map->prec == 0)
	{
		if (map->plus == 1)
			ft_putchar_fd('+', fd, map, 0);
		else if (map->width == 0)
			return ;
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
	}
}

void	ft_putsign_fd(int fd, t_map *map)
{
	if (map->nb == 0 && map->plus == 1 && map->prec == 0)
	{
		return ;
	}
	if (map->typ == 'd' || map->typ == 'i')
	{
		if (map->nb < 0)
		{
			ft_putchar_fd('-', fd, map, 0);
		}
		if (map->nb >= 0 && map->plus == 1)
		{
			ft_putchar_fd('+', fd, map, 0);
			map->plus = 0;
		}
	}
}

void	ft_put0x(int fd, t_map *map)
{
	if (map->nb == 0 && map->prec == 0 && map->hash == 1 && map->typ == 'o')
		ft_putchar_fd('0', fd, map, 0);
	if (map->typ == 'p' || (map->hash == 1 && map->nb != 0 &&
	(map->typ == 'x' || map->typ == 'X' || map->typ == 'o')))
	{
		ft_putchar_fd('0', fd, map, 0);
		if (map->min == 1)
		{
			if (map->typ == 'o')
				map->pfill--;
			else
				map->pad--;
		}
		if (map->typ == 'x' || map->typ == 'p' || map->typ == 'X')
		{
			if (map->typ == 'X')
				ft_putchar_fd('X', fd, map, 0);
			else
				ft_putchar_fd('x', fd, map, 0);
			if (map->min == 1)
				map->pad--;
		}
	}
}

void	ft_nbrflagger_fd(char *s, int fd, t_map *map)
{
	if ((map->plus == 1 && map->nb >= 0) || map->nb < 0)
		map->pad--;
	if (map->zero == 1 && map->pad > 0 && map->prec > -1)
		map->zero = 0;
	if (map->spac == 1 && map->plus == 0 && map->hash == 0 && map->nb >= 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
	if (map->nb == 0 && map->prec == 0 && map->width > 1)
		map->pad++;
	if (map->prec == -1 && map->typ == 'o' && map->hash == 1 && map->nb != 0)
		map->pad--;
	if (map->prec < ft_strlen(s) && map->prec != -1 && map->typ == 'o'
	&& map->hash == 1)
		map->pad--;
	if (map->hash == 1 && map->nb != 0 && map->min == 0)
	{
		if (map->typ == 'o')
			map->pfill--;
		if (map->typ == 'x' || map->typ == 'X')
			map->pad = map->pad - 2;
	}
}

void	ft_nbrputter_fd(char *s, int fd, t_map *map)
{
	map->pfill = map->prec - ft_strlen(s);
	if (map->width > ft_strlen(s) && map->width > map->prec)
		map->pad = (map->prec > ft_strlen(s)) ? map->width - map->prec
		: map->width - ft_strlen(s);
	ft_nbrflagger_fd(s, fd, map);
	if (map->typ == 'p' && map->min == 0)
		map->pad = map->pad - 2;
	while (map->pad > 0 && map->min == 0 && map->zero == 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
	ft_putsign_fd(fd, map);
	ft_put0x(fd, map);
	while (map->zero == 1 && map->pad > 0)
	{
		ft_putchar_fd('0', fd, map, 0);
		map->pad--;
	}
	while (map->pfill > 0)
	{
		ft_putchar_fd('0', fd, map, 0);
		map->pfill--;
	}
	ft_nbrprinter_fd(s, fd, map);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
}
