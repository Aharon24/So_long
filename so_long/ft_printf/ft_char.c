/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:55:38 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:21:53 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int ap)
{
	char	c;

	c = (char)ap;
	return (write(1, &c, 1));
}

int	ft_string(char *a)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (a == NULL)
		return (write(1, "(null)", 6));
	while (a[i] != '\0')
	{
		len += write(1, &a[i], 1);
		i++;
	}
	return (len);
}

int	ft_puthex(unsigned long a)
{
	char	*a_16;
	int		len;

	len = 0;
	a_16 = "0123456789abcdef";
	if (a >= 16)
		len += ft_puthex(a / 16);
	len += write(1, &a_16[a % 16], 1);
	return (len);
}

int	ft_putnbr(int i)
{
	char	c;
	int		len;

	len = 0;
	if (i == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (i < 0)
	{
		len += write(1, "-", 1);
		i = -i;
	}
	if (i >= 10)
		len += ft_putnbr(i / 10);
	c = (i % 10) + 48;
	len += write(1, &c, 1);
	return (len);
}

int	ft_putnbr_(unsigned int u)
{
	char	c;
	int		len;

	len = 0;
	if (u == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (u >= 10)
		len += ft_putnbr(u / 10);
	c = (u % 10) + 48;
	len += write(1, &c, 1);
	return (len);
}
