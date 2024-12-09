/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:56:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 16:59:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	parse_format(const char *format, va_list args);
int	handle_specifier(char specifier, va_list args);
int	print_char(va_list args);
int	print_str(va_list args);

#endif /* FT_PRINTF_H */
