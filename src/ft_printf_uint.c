/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:31:02 by ego               #+#    #+#             */
/*   Updated: 2024/10/21 16:48:04 by ego              ###   ########.fr       */
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
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar('0' + n);
}

int	ft_printf_uint(unsigned int n, t_flags flags)
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
	if (flags.zeros)
		zeros = flags.width - nbr_len;
	if (!flags.left && !flags.zeros)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	s += ft_pad_width('0', zeros);
	s += nbr_len;
	ft_putnbr(n);
	if (flags.left)
		s += ft_pad_width(' ', flags.width - nbr_len - zeros);
	return (s);
}
