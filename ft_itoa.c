/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 04:15:21 by drecours          #+#    #+#             */
/*   Updated: 2017/04/14 11:43:47 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_itoa(long long n, char *nb)
{
	int		i;

	if (n == -9223372036854775807 -1)
		ft_strcpy(nb, "-9223372036854775808");
	i = ft_ilen(n);
	if (n < 0 && n != -9223372036854775807 - 1)
	{
		nb[0] = '-';
		n = -n;
	}
	else if (n == 0)
		nb[0] = '0';
	while (n > 0 && n != -9223372036854775807 - 1)
	{
		i--;
		nb[i] = n % 10 + 48;
		n = n / 10;
	}
}
