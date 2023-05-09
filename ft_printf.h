/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:09:15 by micheng           #+#    #+#             */
/*   Updated: 2023/05/09 15:44:44 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
void			ft_putstr(const char *str);
void			ft_putchar(char c);
static int		ft_parse(va_list ap, const char **str);
void			ft_putnbr(int n);
char			*ft_strdup(char *str);
size_t			ft_strlen(const char *s);
char			*ft_itoa_base(int value, int base);
char			*ft_itoa(int n);
void			ft_putnbr_base(int nbr, char *base);
static char		*ft_assign_num(char *str, long n, int i);

#endif