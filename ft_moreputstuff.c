/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_moreputstuff.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 19:24:51 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/04 19:25:27 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_lastputstuff(char *s, int fd, t_map *map)
{
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
	ft_lastputstuff(s, fd, map);
}
