/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:33:19 by drecours          #+#    #+#             */
/*   Updated: 2017/04/15 14:24:41 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		convxplus(t_env *env, int i)
{
	if (env->conv.sharp == 1 && env->conv.nb[0] != '0' && env->conv.zero == 1)
		ft_putinit(env, (env->conv.conversion == 10) ? "0X" : "0x", -1);
	while (i < env->conv.precision)
		i++;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", -1);
		else
			ft_putinit(env, " ", -1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb);
	if (env->conv.sharp == 1 && env->conv.nb[0] != '0' && env->conv.zero == 0)
		ft_putinit(env, (env->conv.conversion == 10) ? "0X" : "0x", -1);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!( env->conv.nb[0] == '0' && env->conv.precision == 0))
		ft_putinit(env, env->conv.nb, -1);
}

void	convx(va_list args, t_env *env)
{
	int		i;

	convitoabase(args, env, 16);
	i = ft_strlen(env->conv.nb) + ((env->conv.sharp == 1) ? 2 : 0);
	if (env->conv.neg == 1)
	{
		if (env->conv.sharp == 1 && env->conv.nb[0] != '0')
			ft_putinit(env, (env->conv.conversion == 10) ? "0X" : "0x", -1);
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!( env->conv.nb[0] == '0' && env->conv.precision <= 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convxplus(env, i);
}

void	convgx(va_list args, t_env *env)
{
	convx(args, env);
}

void            convp(va_list args, t_env *env)
{
	ft_putinit(env, "0x", -1);
	ft_itoa_base(va_arg(args, long long int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}
