/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/15 17:01:06 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i= 1;
	printf("printf:     |%hx|\n", 42);
	ft_printf("ft_printf : |%x|\n", 0);
	printf("printf:     |%5.x|\n", 10);
	ft_printf("ft_printf : |%5.x|\n", 10);
	printf("printf      |%.5x|\n", 0);
	ft_printf("ft_printf : |%.5x|\n", 0);
	printf("printf      |%0.x|\n", 0);
	ft_printf("ft_printf : |%0.x|\n", 0);
	printf("printf:     |%#.x|\n", 0);
	ft_printf("ft_printf : |%#.x|", 0);
	return 0;
}
