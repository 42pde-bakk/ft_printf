/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:29:13 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 15:27:34 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_amount(unsigned long nb, unsigned long base, t_map *map, char c)
{
	unsigned long	amount;

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

int		ft_absolutely(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_hashcheck(char *str, unsigned long base, t_map *map, char c)
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

char	*ft_itoa_base(unsigned long nb, unsigned long base, t_map *map, char c)
{
	char				*str;
	char				*tab;
	unsigned long int	amount;
	unsigned long int	sign;

	sign = 0;
	amount = ft_amount(nb, base, map, c);
	if (c == 'x')
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (0);
	str = (char*)ft_calloc(amount + 1, sizeof(char));
	if (nb < 0 && base == 10)
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
