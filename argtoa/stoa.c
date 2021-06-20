/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:02:41 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/22 11:08:34 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static void	ftp_fill_ret_stoa(char *ret, char *s, int size, t_ftp_data *data)
{
	int i_ret;
	int i_s;

	i_ret = 0;
	i_s = 0;
	while (i_ret < size)
	{
		if (((data->flags & FLG_DASH) && i_s < data->precision)
				|| (!(data->flags & FLG_DASH)
					&& data->precision + i_ret >= data->width))
			ret[i_ret++] = s[i_s++];
		else
			ret[i_ret++] = ' ';
	}
}

char		*ftp_stoa(char *s, t_ftp_data *data)
{
	char	*ret;
	int		size;

	if (!s)
		s = "(null)";
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flags |= FLG_DASH;
	}
	if (data->precision < 0 || !(data->flags & FLG_PRECISION)
			|| data->precision > ftp_strlen(s))
		data->precision = ftp_strlen(s);
	if ((size = data->precision) < data->width)
		size = data->width;
	if (!(ret = malloc(size + 1)))
		return (0);
	ret[size] = 0;
	ftp_fill_ret_stoa(ret, s, size, data);
	return (ret);
}
