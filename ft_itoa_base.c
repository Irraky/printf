/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:36:47 by drecours          #+#    #+#             */
/*   Updated: 2017/03/11 17:13:28 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ilen_base(int num, int base)
{
	int		l;

	l = (num < 0) ? 2 : 1;
	num = (num < 0) ? -num : num;
	while (base < num)
	{
		base = base * base;
		l++;
	}
	return (l);
}

char	*ft_itoa_base(int num, int base)
{
	char	*str;
	char	*nb;
	int		i;
	int		neg;

	str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	nb = ft_strnew(ilen_base(num, base));
	i = 0;
	if (num == 0)
		return ("0");
	neg = (num < 0) ? -1 : 1;
	num = (num < 0) ? -num : num;
	while (num > 0)
	{
		nb[i] = str[num % base];
		i++;
		num = num / base;
	}
	if (neg < 0)
	nb[i] = '-';
	return (ft_strrev(nb));
}
