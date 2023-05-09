/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:14:18 by micheng           #+#    #+#             */
/*   Updated: 2023/05/10 02:46:56 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			count += ft_parse(args, &str);
		else
		{
			ft_putchar(*str);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}

static int	ft_parse(va_list args, const char **str)
{
	char	*hex_str;

	if (**str == '%')
	{
		(*str)++;
		if (**str == 's')
			ft_putstr(va_arg(args, char *));
		else if (**str == 'd')
			ft_putnbr(va_arg(args, int));
		else if (**str == '%')
			ft_putchar('%');
		else if (**str == 'c')
			ft_putchar(va_arg(args, int));
		else if (**str == 'X' || **str == 'x')
		{
			hex_str = ft_itoa_base(va_arg(args, int), 16);
			if (**str == 'X')
				hex_str = ft_capitalize(hex_str);
			ft_putstr("0x");
			ft_putstr(hex_str);
			free(hex_str);
		}
		return (-1);
	}
	else
		ft_putchar(**str);
	return (0);
}

int	main(void)
{
    int i = 42;
    char *str = "Hello, world!";
	ft_printf("Testing ft_printf\n");
	ft_printf("Integer: %d\n", i);
    ft_printf("String: %s\n", str);
	ft_printf("Hex: %x | HEX: %X\n", i, i);
	ft_printf("Character: %c\n", 'a');
	ft_printf("Percent sign: %%\n");
	ft_printf("Integer: %d | String: %s", i, str);
    return (0);
}
