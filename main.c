/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:34:16 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/15 16:09:13 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	int	result;
	result = ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	printf(">%i\n", result);
	return (0);
}
