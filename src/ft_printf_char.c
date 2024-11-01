/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:34:45 by ego               #+#    #+#             */
/*   Updated: 2024/10/18 15:42:31 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c, t_flags flags)
{
	int	s;

	s = 0;
	if (flags.width > 1 && !flags.left)
		s += ft_pad_width(' ', flags.width - 1);
	s += ft_putchar(c);
	if (flags.width > 1 && flags.left)
		s += ft_pad_width(' ', flags.width - 1);
	return (s);
}
