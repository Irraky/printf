/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/20 16:29:31 by drecours         ###   ########.fr       */
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

static void		ft_init_env(t_env *env)
{
	env->indexstr = -1;
	env->indexbuff = 0;
	env->conversion = -1;
	env->flags = NULL;
	ft_bzero(&env->buffer, BUFF_SIZE);
}

static void		destroy_env(t_env *env)
{
	ft_memdel((void **)&(env->buffer));
	ft_memdel((void **)&(env->str));
	ft_memdel((void **)&(env->flags));
}

static void		ft_get_flags(t_env *env, const char *format)
{
	int		i;
	char	*conversions;

	i = 0;
	conversions = "SspDdiOoUuXxCcEeFfGgAan";
	
}
int				ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	int			i;

	i = 0;
	ft_init_env(&env);
	va_start(args, format);
	while (format[++env.indexstr])
	{
		while (format[env.indexstr] != '%' && format)
			++env.indexstr;
		ft_putinit(&env, (char *)&format[i], env.indexstr - i - 1);
		ft_get_flags(&env, format);
		i = env.indexstr + ft_strlen(env.flags) + 1;
		ft_putinit(&env, tab[env.conversion], -1);  //faire tableau pointeur sur fonction
	}
	va_end(args);
	return 0;
}

int		main(void)
{
	printf("voici une %sqqqqqs de caractere %s %d", "huit", "deux", 15);
	return 0;
}
