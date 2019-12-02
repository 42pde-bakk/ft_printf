/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:29:13 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 16:57:10 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_amount(long long nb, long long base, t_map *map, char c)
{
	long long	amount;

	amount = 0;
	map->nb = nb;
	if (nb == 0)
		amount++;
	if (map->plus == 1 && nb >= 0 && base == 10)
		amount++;
	if (nb < 0 && base == 10)
	{
		amount++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / base;
		amount++;
	}
	if ((map->hash == 1 && (base == 8 || base == 16)) || c == 'p')
		amount = amount + (base / 8);
	return (amount);
}

int		ft_absolutely(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_hashcheck(char *str, long long base, t_map *map, char c)
{
	if ((c == 'p') || (map->hash == 1 && (base == 8 || base == 16)))
	{
		str[0] = '0';
		if (base == 16)
		{
			if (c == 'p')
				str[1] = 'x';
			else
				str[1] = c;
		}
	}
	if (map->plus == 1 && map->nb >= 0 && base == 10)
		str[0] = '+';
	return (str);
}

char	*ft_itoa_base(long long nb, long long base, t_map *map, char c)
{
	char		*str;
	char		*tab;
	long long	amount;
	long long	sign;

	sign = 0;
	amount = ft_amount(nb, base, map, c);
	if (c == 'X')
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (0);
	str = (char*)ft_calloc(amount + 1, sizeof(char));
	if (nb < 0 && base == 10)
		sign = 1;
	str[0] = '-';
	while (amount > sign)
	{
		str[amount - 1] = tab[ft_absolutely(nb % base)];
		amount--;
		nb = nb / base;
	}
	str = ft_hashcheck(str, base, map, c);
	return (str);
}
