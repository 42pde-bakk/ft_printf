/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:42:31 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 16:28:40 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		s[] = "Lookie";
	char		c = '&';
	int			i = 890;
	unsigned	o = 67;
	unsigned	abc = 15;
	unsigned	def = 15;
	int			H = 15;
	char		*str;

	ft_printf("\033[0;31m");
	ft_printf("%% + 10 String: \n");
	ft_printf("%7s\n", s);
	printf("%7s\n", s);
//	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("-10 flag: \n");
	ft_printf("%-10s$\n", s);
	printf("%-10s$\n", s);
//	ft_printf("\033[0m");

	ft_printf("\033[0;32m");
	ft_printf("020 flags: \n");
	ft_printf("%020s\n", s);
	printf("%020s\n", s);
//	ft_printf("\033[0m");

	ft_printf("\033[1;32m");
	ft_printf("String with .4 prec flag: \n");
	ft_printf("%.4s\n", s);
	printf("%.4s\n", s);
//	ft_printf("\033[0m");

	ft_printf("\033[0;33m");
	ft_printf(".*=3 prec flag: \n");
	ft_printf("%.*s\n", 3, s);
	printf("%.*s\n", 3, s);
//	ft_printf("\033[0m");

	ft_printf("\033[1;33m");
	ft_printf("-0. flags \n");
	ft_printf("%-0.s\n", s);
	printf("%-0.s\n", s);
//	ft_printf("\033[0m");

	return 0;
}
