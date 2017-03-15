/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/15 18:04:59 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;

	env.index = 0;
	env.str = format;
	env.buffer[1024];
	va_start(args, format);
	printf("%d", env.index);
	ft_bzero(&env.buffer, 1000);
	va_end(args);
	return 0;
}

int		main(void)
{
	ft_printf("voici une %s chaine de caractere %s %d", "huit", 10, 15, "trois");
	return 0;
}
