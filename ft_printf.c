/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/21 01:13:09 by drecours         ###   ########.fr       */
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

/*static void		destroy_env(t_env *env)
{
	ft_memdel((void **)&(env->buffer));
	ft_memdel((void **)&(env->flags));
}*/

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
		while (format[env.indexstr] != '%' && format[env.indexstr])
			++env.indexstr;
		if (format[env.indexstr] == '%')
		{
			ft_putinit(&env, (char *)&format[i], env.indexstr - i);
			get_data(&env, format);
			i = env.indexstr;
		//	ft_putinit(&env, tab[env.conversion], -1);  //faire tableau pointeur sur fonction
		}
	}
	ft_putstr(env.buffer);
	va_end(args);
	return 0;
}

int		main(void)
{
	ft_printf("voici une %qqqqqs de caractere  \n", "huit", "deux", 15);
	return 0;
}
