/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:29:55 by ego               #+#    #+#             */
/*   Updated: 2024/10/22 14:50:08 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar('0' + n);
}

static int	ft_printf_int_null(t_flags flags)
{
	int	s;

	s = 0;
	if (flags.sign && flags.left)
		s += ft_putchar('+');
	if (flags.space)
		s += ft_putchar(' ');
	s += ft_pad_width(' ', flags.width - (flags.sign || flags.space));
	if (flags.sign && !flags.left)
		s += ft_putchar('+');
	return (s);
}

int	ft_printf_int(int n, t_flags flags)
{
	int	s;
	int	nbr_len;
	int	zeros;

	s = 0;
	nbr_len = ft_nbrlen(n);
	if (!n && flags.precision == 0)
		return (ft_printf_int_null(flags));
	if (!flags.zeros)
		zeros = (flags.precision > nbr_len) * (flags.precision - nbr_len);
	nbr_len += (n < 0) + ((flags.sign || flags.space) && n >= 0);
	if (flags.zeros)
		zeros = flags.width - nbr_len;
	if (!flags.left && !flags.zeros)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	if ((flags.sign || flags.space) && n >= 0)
		ft_putchar('+' * flags.sign + ' ' * flags.space);
	if (n < 0)
		ft_putchar('-');
	s += ft_pad_width('0', zeros);
	s += nbr_len;
	ft_putnbr(n);
	if (flags.left)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	return (s);
}
