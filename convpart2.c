/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:54:51 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 23:52:12 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void			convs(va_list args, t_env *env)
{
	const char	*str = va_arg(args, char *);
	int		i;
	int		j;

	if (str)
	{
		j = -1;
		i = (env->conv.precision > (int)ft_strlen(str)) ? (env->conv.champ -
				ft_strlen(str)) : (env->conv.champ - env->conv.precision);
		if (env->conv.precision < 0)
			i = env->conv.champ - ft_strlen(str);
		if (env->conv.neg == -1)
		{
			while (++j < i)
				ft_putinit(env, " ", -1);
			ft_putinit(env, (char *)str, env->conv.precision);
		}
		else
		{
			ft_putinit(env, (char *)str, env->conv.precision);
			while (++j < i)
				ft_putinit(env, " ", -1);
		}
	}
}

void			convc(va_list args, t_env *env)
{
	int		i;
	char	s[2];
	s[0] = va_arg(args, int);

	i = -1;
	if (env->conv.neg == 1)
	{
		ft_putinit(env, (char *)s, 11);
		while (++i < env->conv.champ - 1)
			ft_putinit(env, " ", -1);
	}
	else
	{
		while (++i < env->conv.champ - 1)
			ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
		ft_putinit(env, (char *)s, 1);
	}
	env->weight = (s[0] == 0) ? env->weight + 1 : env->weight;
}

void			convgd(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convo(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 8, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convp(va_list args, t_env *env)
{
	ft_putinit(env, "0x", -1);
	ft_itoa_base(va_arg(args, long long int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}
