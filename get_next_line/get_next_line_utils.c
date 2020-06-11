/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:52:42 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/06/11 17:18:00 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup_gnl(const char *s1, int n, int startpos)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	if (n == 0)
		return (ft_calloc_gnl(0, 0));
	if (n == -1)
		len = ft_strlen_gnl(s1);
	else
		len = n;
	dup = (char*)ft_calloc_gnl(len + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[startpos + i];
		i++;
	}
	return (dup);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	if (s[0] == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoiner_gnl(char *str, char *buf, int ret)
{
	int		i;
	int		n;
	char	*join;

	i = 0;
	n = 0;
	join = (char*)ft_calloc_gnl(ft_strlen_gnl(str) + ret + 1, sizeof(char));
	if (join == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str && str[i])
	{
		join[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	while (buf && buf[n])
	{
		join[i + n] = buf[n];
		n++;
	}
	return (join);
}

void	ft_bzero_gnl(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
