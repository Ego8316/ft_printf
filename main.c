/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:34:16 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/16 15:49:36 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	int	result;

	result = ft_printf("salut %*i ca va", 10);
	// printf("\n>%i\n", result);
	(void)result;
	// printf("%.4.4i", 3);
	return (0);
}
