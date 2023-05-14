/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:09:15 by micheng           #+#    #+#             */
/*   Updated: 2023/05/14 15:03:30 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
//test libraries
//# include <stdio.h>
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define BASE_10 "0123456789"

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_parse(va_list args, char s);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *s);
char	*ft_itoa_base(unsigned long long num, char *base);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putnbr(int n);
int		format_x_check(va_list args, char str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_toupper(int c);
int		ft_hexdec(unsigned int num, const char s);
void	*ft_calloc(size_t count, size_t size);
int		ft_pointer(void *ptr);

#endif