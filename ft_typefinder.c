/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_typefinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 21:32:40 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/02 21:32:43 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_typefinder4(const char *s, t_map *map, va_list *args)
{
	void			*ptr;
	long long int	*n;
	char			*string;

	if (s[map->pos] == 'p')
	{
		ptr = va_arg(*args, void *);
		string = ft_itoa_base((unsigned long)ptr, 16, map, s[map->pos]);
		ft_putstr_fd(string, 1, map, 0);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, long long int*);
		*n = map->size;
		map->pos++;
	}
}

void	ft_typefinder3(const char *s, t_map *map, va_list *args)
{
	unsigned long long	o;
	long long int		i;
	char				*s;

	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, long long int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'o')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 8, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
}

void	ft_typefinder2(const char *s, t_map *map, va_list *args)
{
	unsigned long long	o;
	char				*string;

	if (s[map->pos] == 'u')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		o = va_arg(*args, unsigned long long);
		string = ft_itoa_base(o, 16, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return ;
	}
}

void	ft_typefinder(const char *s, t_map *map, va_list *args)
{
	char				*string;
	char				c;
	long long			i;

	if (s[map->pos] == 's')
	{
		string = va_arg(*args, char *);
		ft_putstr_fd(string, 1, map, 1);
		map->pos++;
		return ;
	}
	if (s[map->pos] == 'c')
	{
		c = va_arg(*args, int);
		ft_putchar_fd(c, 1, map, 1);
		map->pos++;
		return ;
	}
	typefinder2(s, map, args);
	typefinder3(s, map, args);
	typefinder4(s, map, args);
}
