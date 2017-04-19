/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/19 17:59:40 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	int	i;

	i= 1;
	setlocale(LC_ALL, "");
	ft_printf("ft_printf : |%C|\n", L'Ȣ');
	ft_printf("ft_printf : |%C|", L'鯶');
	return 0;
}
