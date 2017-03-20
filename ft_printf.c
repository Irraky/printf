/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/20 12:41:56 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void		ft_putinit(t_env *env, char *addit, int size)
{
	int		i;

	i = -1;
	while (addit[++i] && (i < size || size == -1))
	{
		env->buffer[env->indexbuff] = addit[i];
		if (env->indexbuff++ >= BUFF_SIZE)
		{
			ft_putstr((char const *)env->buffer);
			ft_bzero(&env->buffer, BUFF_SIZE);
			env->indexbuff = 0;
		}
	}
}

static void		ft_init_env(t_env *env, const char *format)
{
	env->indexstr = -1;
	env->indexbuff = 0;
	env->str = format;
	ft_bzero(&env->buffer, BUFF_SIZE);
}

int		ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	int			i;

	i = 0;
	ft_init_env(&env, format);
	va_start(args, format);
	while (env.str[++env.indexstr])
	{
		while (env.str[env.indexstr] != '%' && env.str)
			++env.indexstr;
		ft_putinit(&env, (char *)&env.str[i], env.indexstr - i);
		i = env.indexstr + 1;
		ft_get_flags(&env);
		ft_putinit(&env, tab[ft_conversion], -1);  //faire tableau pointeur sur fonction
		/*if (env.str[i] == '%')
			ft_search;*/
	}
	printf("%d", env.indexbuff);
	env.indexbuff = 0;
	printf("%s", env.buffer);
	va_end(args);
	return 0;
}

int		main(void)
{
	ft_printf("voici une %sqqqqqs de caractere %s %d", "huit", "deux", 15);
	return 0;
}
