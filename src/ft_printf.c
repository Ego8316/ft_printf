/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:58:43 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/18 16:47:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_spec(char spec, va_list args, t_flags flags)
{
	int	s;

	s = 0;
	if (spec == 'c')
		s = ft_printf_char(va_arg(args, int), flags);
	else if (spec == 's')
		s = ft_printf_str(va_arg(args, char *), flags);
	else if (spec == 'p')
		s = ft_putchar('p');
	else if (spec == 'd' || spec == 'i' || spec == 'u')
		s = ft_putnbr_base(va_arg(args, long long), "0123456789");
	else if (spec == 'x')
		s = ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (spec == 'X')
		s = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (spec == '%')
		s = ft_putchar('%');
	return (s);
}

int	ft_parse_flags(char *format, int i, va_list args, t_flags *flags)
{
	while (format[i] && ft_isflag(format[i]) && ft_isflag(format[i - 1]))
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
		if (format[i] == '*' || ft_isdigit(format[i]))
			i = ft_get_width(format, i, args, flags);
		if (format[i] == '.')
			i = ft_get_precision(format, i, args, flags);
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

	i = -1;
	s = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			flags = ft_reset_flags();
			j = ft_parse_flags(format, i + 1, args, &flags);
			if (flags.spec)
			{
				i = j;
				s += ft_parse_spec(flags.spec, args, flags);
			}
			else
				s += ft_putchar(format[i]);
		}
		else
			s += ft_putchar(format[i]);
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
