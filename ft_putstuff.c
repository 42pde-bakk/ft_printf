/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstuff.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/04 11:29:40 by pde-bakk      ########   odam.nl         */
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

void	ft_putstr_fd(char *s, int fd, t_map *map, int check)
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
		return ;
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
}

void	ft_nbrprinter_fd(char *s, int fd, t_map *map)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, map, 0);
		i++;
	}
}

void	ft_nbrhelper_fd(char *s, int fd, t_map *map, int step)
{
	if (step == 1)
	{
		if (map->prec > ft_strlen(s))
			map->pfill = map->prec - ft_strlen(s);
		if (map->width > ft_strlen(s) && map->width > map->prec)
			map->pad = (map->prec > ft_strlen(s)) ? map->width - map->prec
			: map->width - ft_strlen(s);
		if ((map->plus == 1 && map->nb >= 0) || map->nb < 0)
			map->pad--;
	}
	if (step == 2)
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

void	ft_nbrflagger_fd(char *s, int fd, t_map *map)
{
	if (map->width <= 0 || map->prec <= -1)
	{
		if (map->zero == 1 && (map->typ == 'i' || map->typ == 'd'))
			ft_nbrhelper_fd(s, fd, map, 2);
		while (map->prec == -1 && map->pad > 0 && map->min == 0)
		{
			if (map->zero == 1)
				ft_putchar_fd('0', fd, map, 0);
			else
				ft_putchar_fd(' ', fd, map, 0);
			map->pad--;
		}
		if (map->zero == 0 && (map->typ == 'i' || map->typ == 'd'))
			ft_nbrhelper_fd(s, fd, map, 2);
		while (map->width == 0 && map->pfill > 0)
		{
			ft_putchar_fd('0', fd, map, 0);
			map->pfill--;
		}
	}
}

void	ft_nbrputter_fd(char *s, int fd, t_map *map)
{
	ft_nbrhelper_fd(s, fd, map, 1);
	ft_nbrflagger_fd(s, fd, map);
	if (map->prec > -1 && map->width > map->prec)
	{
		while (map->pad > 0 && map->min == 0)
		{
			ft_putchar_fd(' ', fd, map, 0);
			map->pad--;
		}
		if (map->typ == 'i' || map->typ == 'd')
			ft_nbrhelper_fd(s, fd, map, 2);
		while (map->pfill > 0)
		{
			ft_putchar_fd('0', fd, map, 0);
			map->pfill--;
		}
	}
	ft_nbrprinter_fd(s, fd, map);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
}
