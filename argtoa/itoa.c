/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 08:32:21 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 11:50:55 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../utils.h"
#include "argtoa_utils.h"

static void		ftp_set_flags_itoa(t_ftp_itoa_data *itoa_data, t_ftp_data *data)
{
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flags |= FLG_DASH;
	}
	if (itoa_data->n < 0)
	{
		itoa_data->n = -itoa_data->n;
		data->flags |= FLG_NEGATIVE;
	}
	if (!(data->flags & FLG_PRECISION) || data->precision < 0)
	{
		if (data->flags & FLG_ZERO)
			data->precision = data->width - ((data->flags
						& (FLG_NEGATIVE + FLG_BLANK + FLG_PLUS)) ? 1 : 0);
		if (data->precision < 1 || (data->flags & FLG_DASH))
			data->precision = 1;
	}
	itoa_data->flags = data->flags;
	itoa_data->precision = data->precision;
	itoa_data->width = data->width;
}

static void		ftp_last_fill_itoa(char *ret, int *i, t_ftp_itoa_data *data)
{
	if (!data->n && !data->precision)
	{
		if (data->flags & FLG_NEGATIVE)
			ret[--(*i)] = '-';
		else if (data->flags & FLG_PLUS)
			ret[--(*i)] = '+';
		else if (data->flags & FLG_BLANK)
			ret[--(*i)] = ' ';
	}
}

static void		ftp_fill_ret_itoa(char *ret, char *base,
		t_ftp_itoa_data *data)
{
	int i;

	i = data->nb_chr;
	if (data->flags & FLG_DASH)
		while (data->width-- > data->nb_dgt)
			ret[--i] = ' ';
	if (!data->n && !data->precision)
		ftp_last_fill_itoa(ret, &i, data);
	while (i-- > 0)
	{
		ret[i] = ' ';
		if (data->precision)
		{
			data->precision--;
			ret[i] = '0';
			ftp_last_fill_itoa(ret, &i, data);
		}
		if (data->n)
		{
			ret[i] = base[data->n % data->b_len];
			data->n /= data->b_len;
			ftp_last_fill_itoa(ret, &i, data);
		}
	}
}

char			*ftp_itoa(long long n, char *base, t_ftp_data *data)
{
	t_ftp_itoa_data	itoa_data;
	char			*ret;

	itoa_data.b_len = ftp_strlen(base);
	itoa_data.nb_dgt = 0;
	itoa_data.nb_chr = 0;
	itoa_data.n = n;
	ftp_set_flags_itoa(&itoa_data, data);
	while (n && ++itoa_data.nb_dgt)
		n /= itoa_data.b_len;
	if (itoa_data.nb_dgt < data->precision)
		itoa_data.nb_dgt = data->precision;
	if ((data->flags & FLG_NEGATIVE + FLG_PLUS + FLG_BLANK))
		itoa_data.nb_dgt++;
	if ((itoa_data.nb_chr = itoa_data.nb_dgt) < data->width)
		itoa_data.nb_chr = data->width;
	if (!(ret = malloc(itoa_data.nb_chr + 1)))
		return (0);
	ret[itoa_data.nb_chr] = 0;
	ftp_fill_ret_itoa(ret, base, &itoa_data);
	return (ret);
}
