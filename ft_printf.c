/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/04/25 16:22:14 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putinit(t_env *env, char *addit, int size)
{
	int		i;

	i = -1;
	while (addit[++i] && (i < size || size == -1))
	{
		env->buffer[env->indexbuff] = addit[i];
		if (env->indexbuff++ >= BUFF_SIZE)
		{
			env->weight += 1024;
			ft_putstr((char const *)env->buffer);
			ft_bzero(&env->buffer, BUFF_SIZE);
			env->indexbuff = 0;
		}
	}
}

static void		ft_init_env(t_env *env)
{
	env->indexstr = 0;
	env->indexbuff = 0;
	env->i = 0;
	env->conv.conversion = -1;
	ft_bzero(&env->buffer, BUFF_SIZE);
	ft_bzero(&env->conv.nb, 65);
	ft_bzero(&env->conv.nbp, 65);
	env->weight = 0;
	env->conv.champ = 0;
	env->conv.precision = -1;
	env->conv.neg = 0;
	env->conv.zero = 0;
	env->conv.space = 0;
	env->conv.sharp = 0;
	env->conv.plus = 0;
	env->h = 0;
	env->hh = 0;
	env->l = 0;
	env->ll = 0;
	env->j = 0;
	env->z = 0;
}


static void		destroy_env(t_env *env)
{
	if (env->weight != -1)
		env->weight += ft_strlen(env->buffer);
}


void			cleanit(t_env *env)
{
	env->conv.conversion = -1;
	env->conv.champ = 0;
	env->conv.precision = -1;
	ft_bzero(&env->conv.nb, 65);
	ft_bzero(&env->conv.nbp, 65);
	env->i = env->indexstr;
	env->conv.neg = 0;
	env->conv.zero = 0;
	env->conv.plus = 0;
	env->conv.sharp = 0;
	env->conv.space = 0;
	env->h = 0;
	env->l = 0;
	env->ll = 0;
	env->j = 0;
	env->z = 0;
	env->hh = 0;
}

int				ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	const tconv tabconv[] = {convgs, convs, convp, convgd, convd, convi, convgo,
		convo, convgu, convu, convgx, convx, convgc, convc, convpercent};

	ft_init_env(&env);
	va_start(args, format);
	while (format[env.indexstr])
	{
		while (format[env.indexstr] != '%' && format[env.indexstr])
			++env.indexstr;
		ft_putinit(&env, (char *)&format[env.i], env.indexstr - env.i);
		if (format[env.indexstr] == '%')
		{
			get_data(&env, format, args);
			if (env.conv.conversion != 15 && env.conv.conversion != -1)
				tabconv[env.conv.conversion](args, &env);
			cleanit(&env);
		}
	}
	destroy_env(&env);
	ft_putstr(env.buffer);
	va_end(args);
	return (env.weight);
}
