/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:44:04 by micheng           #+#    #+#             */
/*   Updated: 2023/05/09 15:45:45 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_assign_num(char *str, long n, int i)
{
	str [i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		while (--i != 0)
		{
			str[i] = n % 10 + '0';
			n /= 10;
		}
	}
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	long	temp;
	char	*str;

	n = temp;
	i = 0;
	while (n <= 0)
		i++;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	temp = n;
	return (ft_assign_num(str, temp, i));
}
