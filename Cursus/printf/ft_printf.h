/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:26:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/23 12:51:49 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_fd(int n, int fd);
size_t	ft_nbrlen_base(long long int n, size_t base);
size_t	ft_strlen(const char *s);
int		ft_putnbr_u(unsigned int n, int fd);
int		ft_putnbr_hexa(uintptr_t n, int fd, char format);
int		ft_putnbr_ptr(uintptr_t n, int fd);
size_t	ft_nbrlen_base2(uintptr_t n, size_t base);

#endif
