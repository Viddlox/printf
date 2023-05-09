/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:08:34 by micheng           #+#    #+#             */
/*   Updated: 2023/05/10 02:26:10 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(const char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = b;
	i = 0;
	while (len--)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

char	*ft_capitalize(const char *str)
{
	char	*out;
	int		i;

	out = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!out)
		return (0);
	i = 0;
	while (str[i])
	{
		out[i] = str[i];
		if (str[i] >= 'a' && str[i] <= 'z')
			out[i] -= 32;
		i++;
	}
	out[i] = '\0';
	return (out);
}
