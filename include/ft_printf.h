/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:50:27 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/16 15:47:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// Flags structure
typedef struct s_flags
{
	int		left;
	int		sign;
	int		space;
	int		alt;
	int		zeros;
	int		width;
	int		precision;
	char	spec;
}	t_flags;

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_parse_format(char *format, va_list args);
int		ft_parse_flags(char *format, int i, va_list args, t_flags *flags);

// Flag utilities
t_flags	ft_reset_flags(void);
int		ft_get_precision(char *format, int i, va_list args, t_flags *flags);
int		ft_get_width(char *format, int i, va_list args, t_flags *flags);
void	ft_update_flags(t_flags *flags);
int		ft_isflag(int c);
int		ft_ismodif(int c);
int		ft_isdigit(int c);
int		ft_isspec(int c);

// Strings
int		ft_strlen(char *s);

// Display
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_base(int n, char *base);

#endif