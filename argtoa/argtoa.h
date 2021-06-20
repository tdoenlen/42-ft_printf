/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtoa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:31:08 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 10:33:33 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGTOA_H
# define ARGTOA_H

# include "../data.h"

void ftp_print_c(unsigned char c, t_ftp_data *data);
char *ftp_stoa(char *s, t_ftp_data *data);
char *ftp_itoa(long long n, char *base, t_ftp_data *data);
char *ftp_uitoa(unsigned long long n, char *base, t_ftp_data *data);

#endif
