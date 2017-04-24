/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/24 15:21:02 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include<stdlib.h>
#include <wchar.h>

int		main(void)
{
	int	i;

	i = 1;
	printf("|%*.*x|\n", 7, 2, 34545);
	 ft_printf("|%*.*x|", 7,2, 34545);
	//ft_printf("ft_printf : |%C|\n", L'1');
	//ft_printf("ft_printf : |%C|\n", L'a');

	return 0;
}
