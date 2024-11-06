/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yass <yass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:28:42 by yass              #+#    #+#             */
/*   Updated: 2024/11/03 14:53:08 by yass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(uintptr_t nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + '0'));
		else
			ft_putchar((nbr - 10 + 'a'));
	}
}

int	ft_print_ptr2(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

int	ft_aff_point(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	i += write(1, "0x", 2);
	if (nbr == 0)
		i += write(1, "0", 1);
	else
		i += ft_print_ptr2(nbr);
	return (i);
}

void	ft_recur_hexa(int nbr, char format)
{
	ft_putnbr_hexa((nbr / 16), format);
	ft_putnbr_hexa((nbr % 16), format);
}
