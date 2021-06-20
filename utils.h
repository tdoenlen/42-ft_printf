/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:39:58 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/21 14:00:51 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "flags.h"
# include "data.h"
# include "argtoa/argtoa.h"

# define COUNT_GET 0
# define COUNT_INIT 1
# define COUNT_ADD 2

int			ftp_count(int value, int flag);
void		ftp_putchar(unsigned char c);
void		ftp_putstr(char *s);
char		ftp_is_in_str(char *s, char c);
long int	ftp_strlen(char *str);
void		ftp_print(const char *s, unsigned long *i, va_list *va,
			t_ftp_data *data);

#endif
