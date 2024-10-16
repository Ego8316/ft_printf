/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:58:43 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/16 15:51:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(char *format, int i, va_list args, t_flags *flags)
{
	while (format[i] && ft_isflag(format[i]))
	{
		if (format[i] == '-')
			flags->left = 1;
		if (format[i] == '+')
			flags->sign = 1;
		if (format[i] == ' ')
			flags->space = 1;
		if (format[i] == '0')
			flags->zeros = 1;
		if (format[i] == '#')
			flags->alt = 1;
		if (format[i] == '.')
			i = ft_get_precision(format, i, args, flags);
		if (format[i] == '*' || ft_isdigit(format[i]))
			i = ft_get_width(format, i, args, flags);
		if (ft_isspec(format[i]))
		{
			flags->spec = format[i];
			return (i);
		}
		i++;
	}
	ft_update_flags(flags);
	return (i);
}

int	ft_parse_format(char *format, va_list args)
{
	int		i;
	int		j;
	int		s;
	t_flags	flags;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			flags = ft_reset_flags();
			j = ft_parse_flags(format, i + 1, args, &flags);
			if (flags.spec)
				i = j;
			printf("\n>%i\n", flags.width);
		}
		else
			s += ft_putchar(format[i]);
		i++;
	}
	return (s);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		s;

	if (!format || !(*format))
		return (0);
	va_start(args, format);
	s = ft_parse_format((char *)format, args);
	va_end(args);
	return (s);
}
