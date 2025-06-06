/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:02:47 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:22:15 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formata(const char *a, va_list ap)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (a[i] == 'c')
		len = ft_char(va_arg(ap, int));
	else if (a[i] == 's')
		len = ft_string((char *)va_arg(ap, char *));
	else if (a[i] == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_puthex((unsigned long)va_arg(ap, void *));
	}
	else if (a[i] == 'd' || a[i] == 'i')
		len = ft_putnbr(va_arg(ap, int));
	else if (a[i] == 'u')
		len = ft_putnbr_((unsigned int )va_arg(ap, unsigned int));
	else if (a[i] == 'x')
		len = ft_puthex_x((unsigned long)va_arg(ap, void *));
	else if (a[i] == 'X')
		len = ft_puthex_d((unsigned long)va_arg(ap, void *));
	else if (a[i] == '%')
		len = write(1, "%%", 1);
	return (len);
}
