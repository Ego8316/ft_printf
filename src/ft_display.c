/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:00:18 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/21 17:08:15 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_pad_width(char c, int width)
{
	int	s;

	s = 0;
	while (s < width)
	{
		write(1, &c, 1);
		s++;
	}
	return (s);
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putnstr(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
