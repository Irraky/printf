/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:58:06 by drecours          #+#    #+#             */
/*   Updated: 2017/05/14 18:39:56 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void static		ft_flags(t_env *env)
{
	if (env->conv.nb[0] == '-')
		ft_putinit(env, "-", 1);
	else if (env->conv.space == 1 || env->conv.plus == 1)
		ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", 1);
}

void static		first_flags_d(t_env *env, int max, int lg)
{
	int		flag;

	flag = 0;
	if ((env->conv.nb[0] != '-' && (env->conv.plus == 1 || env->conv.space == 1)
				) || env->conv.nb[0] == '-')
		flag = 1;
	if (env->conv.zero == 1)
		ft_flags(env);
	while (env->conv.neg == 0 && env->conv.champ-- > max + flag)
		ft_putinit(env, (env->conv.zero == 1) ? "0" : "  ", 1);
	if (env->conv.zero == 0)
		ft_flags(env);
	while (env->conv.precision-- > lg - flag)
		ft_putinit(env, "0", 1);
}

void			convd(va_list args, t_env *env)
{
	int		max;
	int		lg;

	convitoa(args, env);
	lg = (int)ft_strlen(env->conv.nb);
	if (env->conv.nb[0] != '-' && (env->conv.plus == 1 || env->conv.space == 1))
		lg++;
	if (env->conv.nb[0] == '0' && env->conv.precision > -1)
		env->conv.zero = 0;
	max = (env->conv.precision > lg) ? env->conv.precision : lg;
	first_flags_d(env, max, lg);
	lg = (int)ft_strlen(env->conv.nb);
	if (env->conv.nb[0] == '-')
	{
		max = (lg == max) ? max - 1 : max;
		ft_putinit(env, &env->conv.nb[1], (lg < max) ? lg : max);
	}
	else if (env->conv.nb[0] != '-' && (env->conv.plus == 1 ||
				env->conv.space == 1))
		ft_putinit(env, env->conv.nb, (lg < max) ? lg : max - 1);
	else
		ft_putinit(env, env->conv.nb, (lg < max) ? lg : max);
	while (env->conv.neg == 1 && env->conv.champ-- > max)
		ft_putinit(env, " ", 1);
}

void			convgd(va_list args, t_env *env)
{
	env->l = 1;
	convd(args, env);
}

void			convi(va_list args, t_env *env)
{
	convd(args, env);
}
