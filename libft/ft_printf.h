/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:51:06 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/24 18:34:40 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		checktype(int i, va_list args);
int		ft_printf(const char *str, ...);
int		ft_ischar(char c);
int		ft_isstring(char *str);
int		ft_isint(int n);
char	*ft_unsigneditoa(unsigned int n);
int		ft_isu(unsigned int n);
int		ft_puthex(unsigned int nb, char *base);
int		caphex(unsigned int n);
int		lowhex(unsigned int n);
int		ft_putp(unsigned long long n);
int		ft_ispointer(unsigned long long n);

#endif
