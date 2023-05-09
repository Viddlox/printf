/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:11:27 by micheng           #+#    #+#             */
/*   Updated: 2023/05/10 02:38:54 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_size(long n_temp, int base)
{
	int		count;

	count = 0;
	if (n_temp < 0)
		n_temp = -n_temp;
	if (n_temp < 0 && base == 10)
		count = 1;
	if (n_temp == 0)
		return (1);
	while (n_temp)
	{
		n_temp /= base;
		count++;
	}
	return (count);
}

static void	ft_base_sign(long n_temp, int base, char *new, int i)
{
	if (n_temp < 0) 
	{
		new[0] = '-';
		n_temp = -n_temp;
	}
	if (i > 0)
		new[0] = '-';
}

char	*ft_itoa_base(int n, int base)
{
	char	*new;
	long	n_temp;
	int		i;

	i = ft_base_size(n, base);
	n_temp = n;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	ft_base_sign(n_temp, base, new, i - 1);
	new[i] = '\0';
	i -= 1;
	while (n_temp) 
	{
		new[i] = "0123456789ABCDEF"[n_temp % base];
		n_temp /= base;
		i--;
	}
	ft_memset(new, '0', i + 1);
	return (new);
}
/*
#include <stdio.h>

int main(void)
{
    char *s1 = ft_itoa_base(2147483647, 10);
    printf("%s\n", s1);
    free(s1);

    char *s2 = ft_itoa_base(2147483647, 16);
    printf("%s\n", s2);
    free(s2);

    char *s3 = ft_itoa_base(2147483647, 2);
    printf("%s\n", s3);
    free(s3);

    return (0);
}
*/