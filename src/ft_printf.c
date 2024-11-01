/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:58:43 by hcavet            #+#    #+#             */
/*   Updated: 2024/11/01 10:26:42 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_spec(char spec, va_list args, t_flags flags)
{
	int	s;

	s = 0;
	if (spec == 'c')
		s = ft_printf_char(va_arg(args, int), flags);
	else if (spec == 's')
		s = ft_printf_str(va_arg(args, char *), flags);
	else if (spec == 'p')
		s = ft_printf_ptr(va_arg(args, void *), flags);
	else if (spec == 'd' || spec == 'i')
		s = ft_printf_int(va_arg(args, int), flags);
	else if (spec == 'u')
		s = ft_printf_uint(va_arg(args, unsigned int), flags);
	else if (spec == 'x' || spec == 'X')
		s = ft_printf_xint(va_arg(args, int), spec, flags);
	else if (spec == '%')
		s = ft_printf_char(spec, flags);
	return (s);
}

static int	ft_parse_flags(char *format, int i, va_list args, t_flags *flags)
{
	while (ft_isflag(format[i]))
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
		if (format[i] == '*' || (ft_isdigit(format[i]) && format[i] != '0'))
			i = ft_get_width(format, i, args, flags);
		if (format[i] == '.')
			i = ft_get_precision(format, i, args, flags);
		if (ft_isspec(format[i]) || (format[i] == '.' && flags->precision > -1))
		{
			ft_update_flags(flags);
			return (i);
		}
		i++;
	}
	return (i);
}

static int	ft_parse_format(char *format, va_list args)
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
			if (ft_isspec(format[j]))
			{
				i = j;
				s += ft_parse_spec(format[j], args, flags);
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
