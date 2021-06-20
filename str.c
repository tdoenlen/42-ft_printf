/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 07:59:46 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/19 12:43:50 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char		ftp_is_in_str(char *s, char c)
{
	while (*s)
		if (*(s++) == c)
			return (1);
	return (0);
}

long int	ftp_strlen(char *str)
{
	long int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
