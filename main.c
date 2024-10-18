/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:34:16 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/18 16:54:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	int	result1;
	int	result2;
	// int	INT_MIN = -2147483648;

	result1 = ft_printf("[%-9.8s]\n", NULL);
	result2 = printf("[%-9.8s]\n", NULL);
	printf("\n>%i\t%i\n", result1, result2);
	return (0);
}
