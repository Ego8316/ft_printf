/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:50:27 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/15 16:05:50 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *, ...);

// String utilities
int	ft_strlen(char *);

// Display utilities
int	ft_putchar(char);
int	ft_putstr(char *);
int	ft_putnbr_base(int, char *);

#endif