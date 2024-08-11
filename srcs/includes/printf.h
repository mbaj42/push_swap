/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:55:40 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 16:23:08 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	small_x_specifier(unsigned int c);
int	large_x_specifier(unsigned int c);
int	p_specifier(void *adress);
int	id_specifier(int c);
int	u_specifier(unsigned int number);
int	ft_putchar(char c);
int	ft_putstr(char *c);

#endif
