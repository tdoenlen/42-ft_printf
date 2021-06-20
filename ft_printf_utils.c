/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:01:17 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 10:35:55 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "argtoa/argtoa.h"
#include "utils.h"

static char	*ftp_print_others(const char *s, unsigned long *i, va_list *va,
		t_ftp_data *data)
{
	if (s[*i] == 'c')
		ftp_print_c((unsigned char)va_arg(*va, int), data);
	else if (s[*i] == 'u')
		return (ftp_uitoa((unsigned int)va_arg(*va, int), "0123456789", data));
	else if (s[*i] == 'x')
		return (ftp_uitoa((unsigned int)va_arg(*va, int), "0123456789abcdef",
					data));
	else if (s[*i] == 'X')
		return (ftp_uitoa((unsigned int)va_arg(*va, int), "0123456789ABCDEF",
					data));
	else if (s[*i] == '%')
		ftp_print_c('%', data);
	else if (s[*i] == 'n')
		*va_arg(*va, int *) = ftp_count(0, COUNT_GET);
	else
		(*i)--;
	return (0);
}

void		ftp_print(const char *s, unsigned long *i, va_list *va,
		t_ftp_data *data)
{
	char *to_put;

	if (s[*i] == 's')
		to_put = ftp_stoa(va_arg(*va, void *), data);
	else if (s[*i] == 'p')
	{
		data->flags |= (FLG_ADDR + FLG_HASHTAG);
		to_put = ftp_uitoa((unsigned long long)va_arg(*va, long long),
				"0123456789abcdef", data);
	}
	else if (s[*i] == 'd' || s[*i] == 'i')
		to_put = ftp_itoa(va_arg(*va, int), "0123456789", data);
	else
		to_put = ftp_print_others(s, i, va, data);
	if (to_put)
	{
		ftp_putstr(to_put);
		free(to_put);
	}
	(*i)++;
}
