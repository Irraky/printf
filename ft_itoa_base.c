/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:36:47 by drecours          #+#    #+#             */
/*   Updated: 2017/03/13 10:40:43 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ilen_base(size_t num, size_t base)
{
	int		l;

	l = 1;
	while (num)
	{
		num /= base;
		l++;
	}
	return (l);
}

char	*ft_itoa_base(size_t num, size_t base)
{
	char	*str;
	char	*nb;
	int		i;

	str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	nb = ft_strnew(ilen_base(num, base));
	i = 0;
	if (num == 0)
		return ("0");
	while (num > 0)
	{
		nb[i] = str[num % base];
		i++;
		num = num / base;
	}
	return (ft_strrev(nb));
}
