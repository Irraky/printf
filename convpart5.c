/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:58:06 by drecours          #+#    #+#             */
/*   Updated: 2017/04/06 16:25:20 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		convdplus(t_env *env)
{
	int		i;

	i = ft_strlen(env->conv.nb) + env->conv.plus;
	i = (env->conv.plus == 0 && env->conv.space == 1) ? i + 1 : i;
	while (i < env->conv.precision)
		i++;
	if (env->conv.nb[0] == '0' && env->conv.nb[1] == '\0')
		i = (env->conv.plus + env->conv.space == 0) ? 0 : 1;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", -1);
		else
			ft_putinit(env, " ", -1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb);
	if ((env->conv.plus == 1 || env->conv.space == 1) && env->conv.nb[0] != '-')
		ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", -1);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!( env->conv.nb[0] == '0' && env->conv.nb[1] == '\0'
				&& env->conv.precision > -1))
		ft_putinit(env, env->conv.nb, -1);
}

void			convd(va_list args, t_env *env)
{
	int		i;

	if (env->conv.conversion ==  4 || env->conv.conversion == 5)
		ft_itoa(va_arg(args, signed int), env->conv.nb);
	i = ft_strlen(env->conv.nb) + env->conv.plus;
	i = (env->conv.plus == 0 && env->conv.space == 1) ? i + 1 : i;
	if (env->conv.neg == 1)
	{
		if (env->conv.plus == 1 || env->conv.space == 1)
			ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", -1);
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!( env->conv.nb[0] == '0' && env->conv.nb[1] == '\0'
					&& env->conv.precision <= 0 && env->conv.champ != 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0' && env->conv.nb[1] == '\0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convdplus(env);
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
	ft_itoa_base(va_arg(args, long int), 10, env->conv.nb);
	convo(args, env);
}
