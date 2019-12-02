/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 15:17:49 by pde-bakk      ########   odam.nl         */
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
	if (check == 1 && map->width > 0)
	{
		map->width--;
//		ft_flagfiller(fd, map, &c);
		while (map->min == 0 && map->width > 0)
		{
			if (map->zero == 0)
				write(fd, " ", 1);
			else
				write(fd, "0", 1);
			map->width--;
		}
	}
	write(fd, &c, 1);
	map->size++;
	while (check == 1 && map->min == 1 && map->width > 0)
	{
		write(1, " ", 1);
		map->width--;
	}
}

void	ft_putstr_fd(char *s, int fd, t_map *map, int check)
{
	int	i;

	i = 0;
	if (check == 1)
		ft_flagfiller(fd, map, s);
	if (map->prec > -1)
		map->pad = map->width - map->prec;
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
//	printf("");
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', 1, map, 0);
		map->pad--;
	}
}

void	ft_nbrputter_fd(char *s, int fd, t_map *map)
{
	if (map->prec > ft_strlen(s))
		map->pfill = map->prec - ft_strlen(s);
	ft_flagfiller(fd, map, s);
	while (map->pfill > 0)
	{
		ft_putchar_fd('0', fd, map, 0);
		map->pfill--;
	}
	ft_putstr_fd(s, fd, map, 0);
	while (map->min == 1 && map->pad > 0)
	{
		ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
}
