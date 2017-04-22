/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/22 17:10:19 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include<stdlib.h>

int		main(void)
{
	int	i;

	i= 1;
	//ft_printf("ft_printf : |%S|\n\n", "ȢȢii");
	printf("printf 0: |%C|\n", 0);
	ft_printf("ft_printf 0: |%C|\n", 0);
	ft_printf("ft_printf : |%C|\n", L'1');
	ft_printf("ft_printf : |%C|\n", L'a');

	return 0;
}
