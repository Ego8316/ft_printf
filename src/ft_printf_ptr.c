/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:55:15 by ego               #+#    #+#             */
/*   Updated: 2024/10/21 16:29:16 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long int p)
{
	int	len;

	if (!p)
		return (1);
	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(unsigned long int p)
{
	if (p > 15)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p < 10)
			ft_putchar('0' + p);
		else
			ft_putchar('a' + (p - 10));
	}
}

static int	ft_printf_ptr_null(t_flags flags)
{
	int	s;

	s = 0;
	if (flags.width && !flags.left)
		s += ft_pad_width(' ', flags.width - 5);
	s += ft_putstr("(nil)");
	if (flags.width && flags.left)
		s += ft_pad_width(' ', flags.width - 5);
	return (s);
}

int	ft_printf_ptr(void *ptr, t_flags flags)
{
	int					s;
	int					ptr_len;
	int					zeros;
	unsigned long int	p;

	if (!ptr)
		return (ft_printf_ptr_null(flags));
	s = 0;
	p = (unsigned long int)ptr;
	ptr_len = ft_ptrlen(p);
	zeros = (flags.precision > ptr_len) * (flags.precision - ptr_len);
	if (!flags.left)
		s += ft_pad_width(' ', flags.width - ptr_len - zeros - 2);
	s += ft_putstr("0x");
	s += ft_pad_width('0', zeros);
	s += ptr_len;
	ft_putptr(p);
	if (flags.left)
		s += ft_pad_width(' ', flags.width - ptr_len - zeros - 2);
	return (s);
}
