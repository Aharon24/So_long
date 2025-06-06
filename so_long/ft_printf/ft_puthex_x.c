/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:28:14 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:22:52 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_x(unsigned int a)
{
	char	*a_16;
	int		len;

	len = 0;
	a_16 = "0123456789abcdef";
	if (a >= 16)
	{
		len += ft_puthex_x(a / 16);
	}
	len += write(1, &a_16[a % 16], 1);
	return (len);
}

int	ft_puthex_d(unsigned int a)
{
	char	*a_16a;
	int		len;

	len = 0;
	a_16a = "0123456789ABCDEF";
	if (a >= 16)
	{
		len += ft_puthex_d(a / 16);
	}
	len += write(1, &a_16a[a % 16], 1);
	return (len);
}
