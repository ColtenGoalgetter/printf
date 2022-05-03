/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrebelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:08:58 by jrebelo-          #+#    #+#             */
/*   Updated: 2022/02/16 15:10:56 by jrebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_ver_base(base) == 1)
	{
		while (base[i] != '\0')
		{
			i++;
		}
		ft_putnbr_base_convertor(nbr, base, i);
	}
	return (0);
}

void	ft_putnbr_base_convertor(int nbr, char *base, int i)
{
	int				p;
	unsigned int	n;

	if (nbr < 0)
	{
		ft_putchar("-");
		n = nbr * (-1);
	}
	else
	{
		n = nbr;
	}
	if (n >= (unsigned int)i)
	{
		ft_putnbr_base_convertor(n / i, base, i);
	}
	p = base[n % i];
	ft_putchar_fd(p, 1);
}

int	ft_ver_base(char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (base[j] == '+' || base[j] == '-' || base[j] == base[j + 1])
		{
			return (0);
		}
		j++;
	}
	if (j <= 1)
	{
		return (0);
	}
	return (1);
}
