
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 18:42:31 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/28 20:56:08 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char		s[] = "Stringvoorbeeld";
	char		c = '&';
	int			i = 890;
	unsigned	o = 67;
	unsigned	abc = 15;
	unsigned	def = 15;
	int			H = 15;
	char		*str;

	ft_printf("\033[1;31m");
	ft_printf("String: \n");
	ft_printf("%s\n", s);
	printf("%-s\n", s);
//	ft_printf("\033[0m");
	ft_printf("\033[1;32m");
	ft_printf("Character: \n");
	ft_printf("%c\n", c);
	printf("%c\n", c);
	ft_printf("\033[0m");
	ft_printf("\033[1;33m");
	ft_printf("Integer: \n");
	ft_printf("%i\n", i);
	printf("%.i\n", i);
	ft_printf("\033[0m");
	ft_printf("\033[1;34m");
	ft_printf("Octal: \n");
	ft_printf("%o\n", o);
	printf("%o\n", o);
	ft_printf("\033[0m");
	ft_printf("\033[1;35m");
	ft_printf("Hexadecimal: \n");
	ft_printf("%x\n", abc);
	printf("%-x\n", abc);
	ft_printf("\033[0m");
	ft_printf("\033[1;36m");
	ft_printf("HeXadecimal: \n");
	ft_printf("%X\n", def);
	printf("%-X\n", def);
	ft_printf("\033[0m");
	ft_printf("\033[1;31m");
	ft_printf("Pointer: \n");
	ft_printf("%p\n", &str);
	printf("%p\n", &str);
	ft_printf("\033[0m");
	return 0;
}
