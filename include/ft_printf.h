/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:50:27 by hcavet            #+#    #+#             */
/*   Updated: 2024/11/01 10:26:30 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

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
}	t_flags;

// ft_printf
int		ft_printf(const char *format, ...);

// ft_printf specifiers
int		ft_printf_char(char c, t_flags flags);
int		ft_printf_str(char *str, t_flags flags);
int		ft_printf_ptr(void *ptr, t_flags flags);
int		ft_printf_int(int n, t_flags flags);
int		ft_printf_uint(unsigned int n, t_flags flags);
int		ft_printf_xint(unsigned int n, char spec, t_flags flags);

// Flag utilities
t_flags	ft_reset_flags(void);
int		ft_get_precision(char *format, int i, va_list args, t_flags *flags);
int		ft_get_width(char *format, int i, va_list args, t_flags *flags);
void	ft_update_flags(t_flags *flags);
int		ft_isflag(int c);
int		ft_ismodif(int c);
int		ft_isdigit(int c);
int		ft_isspec(int c);

// String
int		ft_strlen(char *s);

// Display basics
int		ft_putchar(char c);
int		ft_pad_width(char c, int width);
int		ft_putstr(char *str);
int		ft_putnstr(char *str, int size);

#endif