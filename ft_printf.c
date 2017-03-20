/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/20 11:43:18 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_index_max(t_env *env)
{
	ft_putstr((char const *) env->buffer);
	ft_bzero(&env->buffer, BUFF_SIZE);
	env->index = 0;
}

void	ft_putinit(t_env *env, char *addit)
{
	int		i;

	i = -1;
	while (addit[++i])
	{
		env->buffer[env->index] = addit[i];
		if (env->index++ >= BUFF_SIZE)
			ft_index_max(env);
	}
}

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
		env.buffer[0] = 'a';
		ft_putinit(&env, "hello");
		break;
		/*if (env.str[i] == '%')
			ft_search;*/
	}
	printf("%d", env.index);
	env.index = 0;
	printf("%s", env.buffer);
	va_end(args);
	return 0;
}

int		main(void)
{
	ft_printf("voici une %s chaine de caractere %s %d", "huit", 10, 15, "trois");
	return 0;
}
