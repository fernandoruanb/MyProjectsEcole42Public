/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:38:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 11:35:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	parse_args(const char *format, va_list args);
int	handle_specifiers(const char *format, int index, va_list args);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percentage(void);
int	convert_int_to_str(va_list args);
int	convert_hex_to_str(va_list args, char specifier);
int	ft_strlen(const char *s);

#endif /* FT_PRINTF_H */
