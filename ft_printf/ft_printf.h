/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:45:15 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 16:59:07 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../so_long.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_format(va_list args, const char format, int printl);
int		ft_printf(const char *format, ...);
int		printpercentage(void);
size_t	ft_strlen(const char *s);
int		printhex(unsigned long long num, int z);
int		printptr(unsigned long long pointer);
int		ft_putnbr(int n);
int		ft_putunnbr(unsigned int n);

#endif