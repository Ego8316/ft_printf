/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:00:18 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/16 13:46:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

static int	ft_power(int a, int n)
{
	if (n < 0)
		return (0);
	if (n > 0)
		return (a * ft_power(a, n - 1));
	return (1);
}

static int	ft_base_count_digits(int n, int len_base)
{
	int	digits;

	if (!n)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= len_base;
		digits++;
	}
	return (digits);
}

int	ft_putnbr_base(int n, char *base)
{
	int	len_base;
	int	digits;
	int	power;
	int	i;

	len_base = ft_strlen(base);
	digits = ft_base_count_digits(n, len_base);
	power = ft_power(len_base, digits - 1);
	if (n < 0)
		ft_putchar('-');
	i = n < 0;
	while (digits > 0)
	{
		ft_putchar(base[n / ((1 - 2 * (n < 0)) * power)]);
		n %= (1 - 2 * (n < 0)) * power;
		power /= len_base;
		digits--;
		i++;
	}
	return (i);
}
