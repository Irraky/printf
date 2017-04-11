/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:33:19 by drecours          #+#    #+#             */
/*   Updated: 2017/04/08 10:57:22 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convx(va_list args, t_env *env)
{
	if (env->conv.conversion == 11)
			ft_itoa_base(va_arg(args, unsigned int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convgx(va_list args, t_env *env)
{
	int		i;

	i = -1;
	ft_itoa_base(va_arg(args, unsigned int), 16, env->conv.nbp);
	while (env->conv.nbp[++i])
	{
		if (env->conv.nbp[i] <= 'z' && env->conv.nbp[i] >= 'a')
			env->conv.nb[i] = env->conv.nbp[i] - 32;
		else
			env->conv.nb[i] = env->conv.nbp[i];
	}
	convx(args, env);
}

void            convp(va_list args, t_env *env)
{
	int		i;

	i = ft_strlen(env->conv.nb);
	if (env->conv.neg == 0)
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", 1);
	ft_putinit(env, "0x", -1);
	ft_itoa_base(va_arg(args, long long int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
	if (env->conv.neg == 1)
		while (env->conv.champ-- >= i - 1)
			ft_putinit(env, " ", 1);
}