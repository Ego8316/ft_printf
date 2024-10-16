/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:14:19 by ego               #+#    #+#             */
/*   Updated: 2024/10/16 13:53:03 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	return (ft_ismodif(c) || ft_isdigit(c) || ft_isspec(c));
}

int	ft_ismodif(int c)
{
	return (c == '-' || c == '0' || c == '.' || c == '#' || c == ' '
		|| c == '+' || c == '*');
}

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_isspec(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}
