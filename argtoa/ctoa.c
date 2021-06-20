/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:50:02 by tdoenlen          #+#    #+#             */
/*   Updated: 2021/01/26 09:36:19 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	ftp_print_c(unsigned char c, t_ftp_data *data)
{
	int i;

	i = 0;
	if (data->width < 0)
	{
		data->width = -data->width;
		data->flags |= FLG_DASH;
	}
	if (data->flags & FLG_DASH)
		ftp_putchar(c);
	while (++i < data->width)
		if ((data->flags & FLG_ZERO) && !(data->flags & FLG_DASH))
			ftp_putchar('0');
		else
			ftp_putchar(' ');
	if (!(data->flags & FLG_DASH))
		ftp_putchar(c);
}
