/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 17:03:06 by peerdb         #+#    #+#                */
/*   Updated: 2019/12/05 17:44:11 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char    *ft_floatjoin(char *str, char *decstr)
{
    char    *result;
    int     i;
    int     n;

    i = 0;
    n = 0;
    result = ft_calloc(ft_strlen(str) + ft_strlen(decstr) + 2, sizeof(char));
    if (!result)
        return (0);
    while (str && str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '.';
    i++;
    while (decstr && decstr[n])
    {
        result[i + n] = decstr[n];
        n++;
    }
    free(str);
    free(decstr);
    return (result);
}

int     ft_floatfinder(const char *s, t_map *map, va_list *args)
{
    double      f;
 //   long long   f2;
    long long   dec;
    char        *string;
    char        *decstring;

    if (s[map->pos] == 'f')
    {
        f = va_arg(*args, double);
        dec = (f - (long long)f) * 1000;
        string = ft_itoa_base((long long)f, 10, map, s[map->pos]);
        decstring = ft_itoa_base(dec, 10, map, s[map->pos]);
        string = ft_floatjoin(string, decstring);
        ft_nbrputter_fd(string, 1, map);
        free(string);
        map->pos++;
        return (1);
    }
    return (0);
}