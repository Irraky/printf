/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/18 17:47:55 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	int			i;

	env.index = -1;
	i = -1;
	env.str = format;
	ft_bzero(&env.buffer, BUFF_SIZE);
	va_start(args, format);
	while (env.str[++env.index])
	{
		
		if (env.str[i] == '%')
			ft_search;
	}
	printf("%d", env.index);
	va_end(args);
	return 0;
}

int		main(void)
{
	ft_printf("voici une %s chaine de caractere %s %d", "huit", 10, 15, "trois");
	return 0;
}
