/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:29:13 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 15:49:21 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_amount(unsigned long nb, unsigned long base)
{
	unsigned long	amount;

	amount = 0;
	if (nb == 0)
	{
		amount++;
		return (amount);
	}
	if (nb < 0)
	{
		amount++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / base;
		amount++;
	}
	return (amount);
}

int		ft_absolutely(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(unsigned long nb, unsigned long base, char c)
{
	char				*str;
	char				*tab;
	unsigned long int	amount;
	unsigned long int	sign;

	sign = 0;
	amount = ft_amount(nb, base);
	if (c == 'x')
		tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	else
		tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	if (nb < 0 && base == 10)
		sign = 1;
	str = (char*)ft_calloc(amount + 1, sizeof(char));
	if (sign == 1)
		str[0] = '-';
	while (amount > sign)
	{
		str[amount - 1] = tab[ft_absolutely(nb % base)];
		amount--;
		nb = nb / base;
	}
	return (str);
}
