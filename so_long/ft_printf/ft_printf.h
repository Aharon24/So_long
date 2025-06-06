/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:34:33 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:22:35 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
//#include <stdio.h>

int	ft_printf(const	char *format, ...);
int	ft_formata(const char *a, va_list ap);
int	ft_char(int ap);
int	ft_string(char *ap);
int	ft_puthex(unsigned long a);
int	ft_putnbr(int i);
int	ft_putnbr_(unsigned int i);
int	ft_puthex_x(unsigned int a);
int	ft_puthex_d(unsigned int a);

#endif