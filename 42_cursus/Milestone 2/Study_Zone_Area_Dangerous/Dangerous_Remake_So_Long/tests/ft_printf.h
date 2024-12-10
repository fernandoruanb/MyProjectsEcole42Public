/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 21:28:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	parse_format(const char *format, va_list args);
int	handle_specifier(char specifier, va_list args);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_percentage(void);
int	ft_strlen(const char *s);

#endif /* FT_PRINTF_H */
