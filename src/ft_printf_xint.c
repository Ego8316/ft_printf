/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:39:57 by ego               #+#    #+#             */
/*   Updated: 2024/10/22 14:23:20 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_putnbr(unsigned int n, char spec)
{
	if (n > 15)
	{
		ft_putnbr(n / 16, spec);
		ft_putnbr(n % 16, spec);
	}
	else
	{
		if (n < 10)
			ft_putchar('0' + n);
		else
			ft_putchar((spec - 23) + (n - 10));
	}
}

int	ft_printf_xint(unsigned int n, char spec, t_flags flags)
{
	int	s;
	int	nbr_len;
	int	zeros;

	s = 0;
	nbr_len = ft_nbrlen(n);
	if (!n && flags.precision == 0)
		return (ft_pad_width(' ', flags.width));
	if (!flags.zeros)
		zeros = (flags.precision > nbr_len) * (flags.precision - nbr_len);
	nbr_len += 2 * (flags.alt && n > 0);
	if (flags.zeros)
		zeros = flags.width - nbr_len;
	if (!flags.left && !flags.zeros)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	if (flags.alt && spec == 'x' && n > 0)
		ft_putstr("0x");
	else if (flags.alt && spec == 'X' && n > 0)
		ft_putstr("0X");
	s += ft_pad_width('0', zeros);
	s += nbr_len;
	ft_putnbr(n, spec);
	if (flags.left)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	return (s);
}
