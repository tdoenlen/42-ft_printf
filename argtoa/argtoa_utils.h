/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtoa_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 10:09:49 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 10:33:55 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGTOA_UTILS_H
# define ARGTOA_UTILS_H

typedef struct	s_ftp_itoa_data
{
	int			nb_dgt;
	int			nb_chr;
	long long	b_len;
	long long	n;
	int			flags;
	long		width;
	int			precision;
}				t_ftp_itoa_data;

typedef struct	s_ftp_uitoa_data
{
	int					nb_dgt;
	int					nb_chr;
	unsigned long long	b_len;
	unsigned long long	n;
	int					flags;
	long				width;
	int					precision;
}				t_ftp_uitoa_data;

#endif
