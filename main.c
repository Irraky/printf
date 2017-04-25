/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/25 16:45:15 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include<stdlib.h>
#include <wchar.h>
#include <locale.h>

int		main(void)
{
	int	i;

	i = 1;
	//printf("|valeur printf: %d|\n", printf("%S", setlocale(LC_ALL, "米")));
	printf("|valeur ft_printf: %d|\n", ft_printf("%S", L"Á±≥"));
	//ft_printf("{%}");
	// printf("|%*.*d|\n", 7, 2, );
	 //ft_printf("|%*.*d|", 7);
//	ft_printf("ft_printf : |%C|\n", L'1');
	//ft_printf("ft_printf : |%C|\n", L'a');

	return 0;
}
