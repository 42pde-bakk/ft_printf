/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 20:51:26 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/02 20:47:11 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bonusflagfinder(const char *s, t_map *map, va_list *args)
{
	if (s[map->pos] == 'l' && s[map->pos + 1] == 'l')
	{
		map->ll = 1;
		map->pos = map->pos + 2;
	}
	if (s[map->pos] == 'l')
	{
		map->l = 1;
		map->pos++;
	}
	if (s[map->pos] == 'h' && s[map->pos + 1] == 'h')
	{
		map->hh = 1;
		map->pos = map->pos + 2;
	}
	if (s[map->pos] == 'h')
	{
		map->h = 1;
		map->pos++;
	}
}
void	ft_thirdflagfinder(const char *s, t_map *map, va_list *args)
{
	while (s[map->pos] >= '0' && s[map->pos] <= '9' && s[map->pos - 1] != '.')
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

void	ft_secondflagfinder(const char *s, t_map *map, va_list *args)
{
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
	if (s[map->pos] == '*' && s[map->pos - 1] != '.')
	{
		map->width = va_arg(*args, int);
		map->pos++;
	}
}

void	ft_flagfinder(const char *s, t_map *map, va_list *args)
{
	while (ft_strchr("cspdiouxX%nfge", s[map->pos]) == 0)
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
		if (s[map->pos] == ' ')
		{
			map->spac = 1;
			map->pos++;
		}
		ft_secondflagfinder(s, map, args);
		ft_thirdflagfinder(s, map, args);
		ft_bonusflagfinder(s, map, args);
	}
	return ;
}

void	ft_flagfiller(int fd, t_map *map, char *s)
{
	map->pad = map->width - ft_strlen(s);
//	printf("map->pad = %d\n", map->pad);
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
