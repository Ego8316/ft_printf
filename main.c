/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:34:16 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/22 15:02:18 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "include/ft_printf.h"

int	main(void)
{
	int		result1;
	int		result2;
	char	*string = "salut";

	result1 = ft_printf("[%***d]\n", 5, INT_MIN);
	result2 = printf("[%***d]\n", 5, INT_MIN);
	printf("\n>%i\t%i\n", result1, result2);
	return (0);
}
