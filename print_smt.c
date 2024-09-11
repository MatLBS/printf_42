/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_smt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:01:22 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/23 15:56:11 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		print_str("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		print_char((int)*str);
		++str;
		++count;
	}
	return (count);
}

int	print_digit(long n, int base, int flag)
{
	int		count;
	char	*symbols;

	if (flag == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, flag) + 1);
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base, flag);
		return (count + print_digit(n % base, base, flag));
	}
}

int	calcul(unsigned long address, int i, char *buffer)
{
	int	digit;
	int	count;

	count = 0;
	digit = 0;
	while (address > 0)
	{
		digit = address % 16;
		if ((digit) < 10)
			buffer[--i] = '0' + digit;
		else
			buffer[--i] = 'a' + (digit - 10);
		address /= 16;
		count++;
	}
	buffer[--i] = 'x';
	buffer[--i] = '0';
	count += 2;
	while (buffer[i] != '\0')
	{
		print_char(buffer[i]);
		i++;
	}
	return (count);
}

int	print_address(void *ptr)
{
	char			buffer[20];
	int				i;
	int				count;
	unsigned long	address;

	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	i = sizeof(buffer) - 1;
	buffer[i] = '\0';
	count = calcul(address, i, buffer);
	return (count);
}
