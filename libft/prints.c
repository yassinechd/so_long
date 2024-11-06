/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yass <yass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:28:36 by yass              #+#    #+#             */
/*   Updated: 2024/11/03 14:52:59 by yass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (ft_strlen((str)));
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (nb < 0)
	{
		nb *= -1;
		i += write(1, "-", 1);
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_putnbr_hexa(unsigned int nbr, char format)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_putnbr_hexa((nbr / 16), format);
		i += ft_putnbr_hexa((nbr % 16), format);
	}
	else
	{
		if (nbr <= 9)
			i += ft_putchar(nbr + '0');
		else if (format == 'x')
			i += ft_putchar(nbr - 10 + 'a');
		else if (format == 'X')
			i += ft_putchar(nbr - 10 + 'A');
	}
	return (i);
}
