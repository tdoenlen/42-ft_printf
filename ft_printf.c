/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:08:24 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/21 13:22:05 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static int	ftp_atoi(const char *s, unsigned long *i)
{
	int ret;

	ret = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
		ret = (ret * 10) + (s[(*i)++] - '0');
	return (ret);
}

static void	ftp_update_flags(int *flags, char c)
{
	if (c == '-')
		*flags |= FLG_DASH;
	else if (c == '0')
		*flags |= FLG_ZERO;
	else if (c == '+')
		*flags |= FLG_PLUS;
	else if (c == '#')
		*flags |= FLG_HASHTAG;
	else if (c == ' ')
		*flags |= FLG_BLANK;
}

static void	ftp_check_flags(const char *s, unsigned long *i, va_list *va)
{
	t_ftp_data	data;
	char		c;

	data.width = 0;
	data.precision = 0;
	data.flags = 0;
	while ((c = s[*i]) &&
			(ftp_is_in_str(".-*# +", c) || (c >= '0' && c <= '9')))
		if (c == '*' && (*i)++ && (data.flags |= FLG_WIDTH))
			data.width = va_arg(*va, int);
		else if (c == '.' && (data.flags |= FLG_PRECISION))
			if (s[++(*i)] == '*')
			{
				data.precision = va_arg(*va, int);
				(*i)++;
			}
			else
				data.precision = ftp_atoi(s, i);
		else if (c >= '1' && c <= '9' && (data.flags |= FLG_WIDTH))
			data.width = ftp_atoi(s, i);
		else
			ftp_update_flags(&(data.flags), s[(*i)++]);
	ftp_print(s, i, va, &data);
}

int			ft_printf(const char *s, ...)
{
	unsigned long	i;
	va_list			va;

	i = 0;
	ftp_count(0, COUNT_INIT);
	va_start(va, s);
	while (s[i])
		if (s[i] == '%')
		{
			i++;
			ftp_check_flags(s, &i, &va);
		}
		else
			ftp_putchar(s[i++]);
	va_end(va);
	return (ftp_count(0, COUNT_GET));
}
