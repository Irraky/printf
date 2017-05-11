/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:58:06 by drecours          #+#    #+#             */
/*   Updated: 2017/05/11 18:17:10 by drecours         ###   ########.fr       */
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

void			convd(va_list args, t_env *env)
{
	int		max;
	int		lg;

	convitoa(args, env);
	lg = (int)ft_strlen(env->conv.nb);
	max = (env->conv.precision < lg && env->conv.precision > -1) ?
		env->conv.precision : lg;
	if (env->conv.zero == 1)
		ft_flags(env);
	while (env->conv.neg == 0 && env->conv.champ-- > max)
		ft_putinit(env, (env->conv.zero == 1) ? "0" : " ", 1);
	if (env->conv.zero == 0)
		ft_flags(env);
	while (env->conv.precision-- > lg)
		ft_putinit(env, "0", 1);
	if (env->conv.nb[0] == '-')
	{
		max = ((int)ft_strlen(env->conv.nb) == max) ? max - 1 : max;
		ft_putinit(env, &env->conv.nb[1], max);
	}
	else
		ft_putinit(env, env->conv.nb, max);
	while (env->conv.neg == 1 && env->conv.champ-- >= max)
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
