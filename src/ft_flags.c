/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:47:07 by ego               #+#    #+#             */
/*   Updated: 2024/10/21 15:55:44 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_reset_flags(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.sign = 0;
	flags.space = 0;
	flags.alt = 0;
	flags.zeros = 0;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}

int	ft_get_width(char *format, int i, va_list args, t_flags *flags)
{
	int	j;

	j = i;
	if (format[j] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->left = 1;
			flags->width *= -1;
		}
		j++;
	}
	else
	{
		flags->width = 0;
		while (ft_isdigit(format[j]))
		{
			flags->width = flags->width * 10 + (format[j] - '0');
			j++;
		}
	}
	return (j);
}

int	ft_get_precision(char *format, int i, va_list args, t_flags *flags)
{
	int	j;

	j = i + 1;
	if (format[j] == '*')
	{
		flags->precision = va_arg(args, int);
		return (j + 1);
	}
	flags->precision = 0;
	while (ft_isdigit(format[j]))
	{
		flags->precision = flags->precision * 10 + (format[j] - '0');
		j++;
	}
	return (j);
}

void	ft_update_flags(t_flags *flags)
{
	if (flags->space && flags->sign)
		flags->space = 0;
	if (flags->zeros && (flags->left || flags->precision >= 0))
		flags->zeros = 0;
	return ;
}
