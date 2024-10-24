/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:33 by ego               #+#    #+#             */
/*   Updated: 2024/10/22 14:36:36 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_str_null(t_flags flags)
{
	int		s;

	s = 0;
	if (flags.precision > -1 && flags.precision < 6)
	{
		if (!flags.left)
			s += ft_pad_width(' ', flags.width - flags.precision);
		s += ft_putnstr("(null)", flags.precision);
		if (flags.left)
			s += ft_pad_width(' ', flags.width - flags.precision);
	}
	else
	{
		if (!flags.left)
			s += ft_pad_width(' ', flags.width - 6);
		s += ft_putstr("(null)");
		if (flags.left)
			s += ft_pad_width(' ', flags.width - 6);
	}
	return (s);
}

int	ft_printf_str(char *str, t_flags flags)
{
	int	s;
	int	size;

	s = 0;
	if (!str)
		return (ft_printf_str_null(flags));
	size = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision < size)
		size = flags.precision;
	if (!flags.left)
		s += ft_pad_width(' ', flags.width - size);
	s += ft_putnstr(str, size);
	if (flags.left)
		s += ft_pad_width(' ', flags.width - size);
	return (s);
}
