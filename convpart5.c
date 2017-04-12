/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:58:06 by drecours          #+#    #+#             */
/*   Updated: 2017/04/12 18:37:36 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void		convdpositif(t_env *env, int max)
{
	int		flag;

	flag = 0;
	if (env->conv.nb[0] == '0')
		env->conv.precision++;
	if (env->conv.precision >= 0)
		env->conv.zero = 0;
	if (env->conv.space == 1 || env->conv.plus == 1)
	{
		max++;
		if (env->conv.zero == 1)
		{
			flag = 1;
			ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", 1);
		}
	}
	while (env->conv.neg == 0 && env->conv.champ > max)
	{
		ft_putinit(env, (env->conv.zero == 0) ? " " : "0", 1);
		env->conv.champ--;
	}
	if (flag == 0)
		if (env->conv.space == 1 || env->conv.plus == 1)
			ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", 1);
	while (env->conv.precision-- > (int)ft_strlen(env->conv.nb))
		ft_putinit(env, "0", 1);
	if (!(env->conv.nb[0] == '0' && env->conv.precision == 0))
		ft_putinit(env, env->conv.nb, -1);
	while (env->conv.neg == 1 && env->conv.champ-- > max)
		ft_putinit(env, " ", 1);
}

void			convd(va_list args, t_env *env)
{
	int		flag;
	int		max;

	flag = 0;
	if (env->conv.conversion ==  4 || env->conv.conversion == 5)
		ft_itoa(va_arg(args, signed int), env->conv.nb);
	max = (env->conv.precision > (int)ft_strlen(env->conv.nb)) ?
		env->conv.precision : ft_strlen(env->conv.nb);
	if (env->conv.nb[0] == '-')
	{
		if (env->conv.zero == 1)
		{
			flag++;
			ft_putinit(env, "-", 1);
		}
		while(env->conv.neg == 0 && env->conv.champ-- > max)
			ft_putinit(env, (env->conv.zero == 0) ? " " : "0", 1);
		if (flag == 0)
			ft_putinit(env, "-", 1);
		while (env->conv.precision-- > (int)ft_strlen(env->conv.nb))
			ft_putinit(env, "0", 1);
		if (!( env->conv.nb[0] == '0' && env->conv.precision == 0))
			ft_putinit(env, &env->conv.nb[1], -1);
		while (env->conv.neg == 1 && env->conv.champ-- > max)
			ft_putinit(env, " ", 1);
	}
	else
		convdpositif(env, max);
}

void			convgd(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long int), 10, env->conv.nb);
	convd(args, env);
}

void			convi(va_list args, t_env *env)
{
	convd(args, env);
}

void			convgo(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long int), 8, env->conv.nb);
	convo(args, env);
}
