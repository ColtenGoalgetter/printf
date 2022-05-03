/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrebelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:39:58 by jrebelo-          #+#    #+#             */
/*   Updated: 2022/02/16 13:26:13 by jrebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./libft/libft.h"

char	*dec = "0123456789";
char	*hex = "0123456789abcdef";
char	*HEX = "0123456789ABCDEF";

int	ft_printf(const char *format, ...);
int	ft_printf_arg(const char *format, int i, va_list ap);
int	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base_convertor(int nbr, char *base, int i);
int	ft_ver_base(char *base);
int	ft_putchar(const char *c);
int	ft_putstr(const char *s);

#endif
