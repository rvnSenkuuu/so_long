/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:37:32 by tkara2            #+#    #+#             */
/*   Updated: 2024/05/29 18:05:53 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_putnbr_hex(unsigned long long int n, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex(n / 16, format);
	len += ft_putchar(base[n % 16]);
	return (len);
}
