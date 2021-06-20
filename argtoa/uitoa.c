/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:23:06 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 11:31:45 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../utils.h"
#include "argtoa_utils.h"

static void		ftp_set_flags_uitoa(t_ftp_uitoa_data *uitoa_data,
		t_ftp_data *data)
{
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flags |= FLG_DASH;
	}
	if ((!uitoa_data->n && !(data->flags & FLG_ADDR))
			|| uitoa_data->b_len != 16)
		data->flags &= ~FLG_HASHTAG;
	if (!(data->flags & FLG_PRECISION) || data->precision < 0)
	{
		if (data->flags & FLG_ZERO)
			data->precision = data->width - (data->flags & FLG_HASHTAG ? 2 : 0);
		if (data->precision < 1 || (data->flags & FLG_DASH))
			data->precision = 1;
	}
	uitoa_data->flags = data->flags;
	uitoa_data->precision = data->precision;
	uitoa_data->width = data->width;
}

static void		ftp_last_fill_uitoa(char *ret, int *i, char *base,
		t_ftp_uitoa_data *data)
{
	if (!data->n && !data->precision && (data->flags & FLG_HASHTAG))
	{
		ret[--(*i)] = base[10] + 23;
		ret[--(*i)] = '0';
	}
}

static void		ftp_fill_ret_uitoa(char *ret, char *base,
		t_ftp_uitoa_data *data)
{
	int i;

	i = data->nb_chr;
	if (data->flags & FLG_DASH)
		while (data->width-- > data->nb_dgt)
			ret[--i] = ' ';
	if (!data->n && !data->precision)
		ftp_last_fill_uitoa(ret, &i, base, data);
	while (i-- > 0)
	{
		ret[i] = ' ';
		if (data->precision)
		{
			data->precision--;
			ret[i] = '0';
			ftp_last_fill_uitoa(ret, &i, base, data);
		}
		if (data->n)
		{
			ret[i] = base[data->n % data->b_len];
			data->n /= data->b_len;
			ftp_last_fill_uitoa(ret, &i, base, data);
		}
	}
}

char			*ftp_uitoa(unsigned long long n, char *base, t_ftp_data *data)
{
	t_ftp_uitoa_data	uitoa_data;
	char				*ret;

	uitoa_data.b_len = ftp_strlen(base);
	uitoa_data.nb_dgt = 0;
	uitoa_data.nb_chr = 0;
	uitoa_data.n = n;
	ftp_set_flags_uitoa(&uitoa_data, data);
	while (n && ++uitoa_data.nb_dgt)
		n /= uitoa_data.b_len;
	if (uitoa_data.nb_dgt < data->precision)
		uitoa_data.nb_dgt = data->precision;
	if (data->flags & FLG_HASHTAG)
		uitoa_data.nb_dgt += 2;
	if ((uitoa_data.nb_chr = uitoa_data.nb_dgt) < data->width)
		uitoa_data.nb_chr = data->width;
	if (!(ret = malloc(uitoa_data.nb_chr + 1)))
		return (0);
	ret[uitoa_data.nb_chr] = 0;
	ftp_fill_ret_uitoa(ret, base, &uitoa_data);
	return (ret);
}
