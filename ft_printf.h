/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:59:47 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/23 13:01:50 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, int flag);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);
int	print_address(void *ptr);
int	print_unsigned_digit(unsigned long n, int base);

#endif
