/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:29:13 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/12/04 15:52:23 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_amount(long long nb, long long base, t_map *map)
{
	long long	amount;

	amount = 0;
	map->nb = nb;
	if (nb == 0)
		amount++;
	if (nb < 0 && base == 10)
	{
		map->plus = 0;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / base;
		amount++;
	}
	return (amount);
}

int		ft_absolutely(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(long long nb, long long base, t_map *map, char c)
{
	char		*str;
	char		*tab;
	long long	amount;

	amount = ft_amount(nb, base, map);
	if (c == 'X')
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (0);
	str = (char*)ft_calloc(amount + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (amount > 0)
	{
		str[amount - 1] = tab[ft_absolutely(nb % base)];
		amount--;
		nb = nb / base;
	}
	return (str);
}
