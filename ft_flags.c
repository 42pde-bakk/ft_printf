/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 20:51:26 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 17:34:47 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagfinder(const char *s, t_map *map, va_list *args)
{
	if (s[map->pos] == '-')
	{
		map->min = 1;
		map->pos++;
	}
	if (s[map->pos] == '+')
	{
		map->plus = 1;
		map->pos++;
	}
	while (s[map->pos] == ' ')
	{
		map->spac = 1;
		map->pos++;
	}
	if (s[map->pos] == '#')
	{
		map->hash = 1;
		map->pos++;
	}
	if (s[map->pos] == '0')
	{
		map->zero = 1;
		map->pos++;
	}
	if (s[map->pos] == '*')
	{
		map->width = va_arg(*args, int);
		map->pos++;
	}
	while (s[map->pos] >= '0' && s[map->pos] <= '9')
	{
		map->width = map->width * 10 + s[map->pos] - 48;
		map->pos++;
	}
	if (s[map->pos] == '.')
	{
		map->pos++;
		map->prec = 0;
		while (s[map->pos] >= '0' && s[map->pos] <= '9')
		{
			map->prec = map->prec * 10 + s[map->pos] - 48;
			map->pos++;
		}
		if (s[map->pos] == '*')
		{
			map->prec = va_arg(*args, int);
			map->pos++;
		}
	}
}

void	ft_flagfiller(int fd, t_map *map, char *s)
{
	map->pad = map->width - ft_strlen(s);
	while (map->min == 0 && map->pad > 0)
	{
		if (map->zero == 1)
			ft_putchar_fd('0', fd, map, 0);
		else
			ft_putchar_fd(' ', fd, map, 0);
		map->pad--;
	}
	return ;
}
