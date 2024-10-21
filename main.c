/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:34:16 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/21 17:07:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	int		result1;
	int		result2;
	char	*string = "salut";
	long int	INT_MIN = -2147483648;

	result1 = ft_printf("[%#20.5x]\n", 15, 10);
	result2 = printf("[%#20.5x]\n", 15, 10);
	printf("\n>%i\t%i\n", result1, result2);
	return (0);
}
