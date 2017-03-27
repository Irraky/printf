/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:06:14 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 21:26:42 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void			convgs(va_list args, t_env *env)
{
	(void)args;
	(void)env;
}

void			convgo(va_list args, t_env *env)
{
	(void)args;
	(void)env;
}

void			convgx(va_list args, t_env *env)
{
	int		i;

	i = -1;
	ft_itoa_base(va_arg(args, unsigned int), 16, env->conv.nb);
	while (env->conv.nb[++i])
	{
		if (env->conv.nb[i] <= 'z' && env->conv.nb[i] >= 'a')
			env->conv.nbp[i] = env->conv.nb[i] - 32;
		else
			env->conv.nbp[i] = env->conv.nb[i];
	}
	ft_putinit(env, env->conv.nbp, -1);
}

void			convgc(va_list args, t_env *env)
{
	(void)args;
	(void)env;
}

void			convpercent(va_list args, t_env *env)
{
	int		i;

	(void)args;
	i = -1;
	if (env->conv.neg == 1)
	{
		ft_putinit(env, "%", -1);
		while (++i < env->conv.champ - 1)
			ft_putinit(env, " ", -1);
	}
	else
	{
		while (++i < env->conv.champ - 1)
			ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
		ft_putinit(env, "%", -1);
	}
}
