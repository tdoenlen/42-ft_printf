/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:40:48 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/21 13:51:20 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int		ftp_count(int value, int flag)
{
	static int c;

	if (flag == COUNT_INIT)
		c = value;
	else if (flag == COUNT_ADD)
		c += value;
	return (c);
}

void	ftp_putchar(unsigned char c)
{
	write(1, &c, 1);
	ftp_count(1, COUNT_ADD);
}

void	ftp_putstr(char *s)
{
	while (*s)
		ftp_putchar(*(s++));
}
