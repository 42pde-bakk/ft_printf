/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 19:23:08 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/27 15:02:58 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s1) + 1;
	dup = (char*)malloc(i);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, i);
	return (dup);
}
