/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:11:27 by micheng           #+#    #+#             */
/*   Updated: 2023/05/09 16:52:26 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_putnbr_base(int nbr, char *base)
{
	
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*res;
	int		len;
	int		negative;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	str = itoa(n);
	res = ft_putnbr_base(str, base);
	return (res);
}

int	main(void)
{
	ft_itoa_base(2147483647, 10);
	ft_itoa_base(2147483647, 2);
	ft_itoa_base(2147483647, 16);
	return (0);
}
