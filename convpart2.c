/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:54:51 by drecours          #+#    #+#             */
/*   Updated: 2017/04/26 16:25:17 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			convs(va_list args, t_env *env)
{
	const char	*str = va_arg(args, char *);
	int		i;
	int		j;

	if (str && env->l == 0)
	{
		j = -1;
		i = (env->conv.precision > (int)ft_strlen(str)) ? (env->conv.champ -
				ft_strlen(str)) : (env->conv.champ - env->conv.precision);
		i = (env->conv.precision < 0) ? env->conv.champ - ft_strlen(str) : i;
		if (env->conv.neg == 0)
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
	else if (env->l == 1)
		while (*str)
			trick(*str++, env);
	else
		ft_putinit(env, "(null)", -1);
}

void			convc(va_list args, t_env *env)
{
	int		i;
	wchar_t	 s;
	s = va_arg(args, wchar_t);

	i = -1;
	if (s)
	{
		if (env->conv.neg == 1)
		{
			trick(s, env);
			while (++i < env->conv.champ - 1)
				ft_putinit(env, " ", -1);
		}
		else
		{
			while (++i < env->conv.champ - 1)
				ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
			trick(s, env);
		}
	}
	else
		env->weight += 1;
}

static void			convoplus(t_env *env)
{
	int		i;

	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	while (i < env->conv.precision)
		i++;
	if (env->conv.nb[0] == '0')
		i = env->conv.sharp;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", -1);
		else
			ft_putinit(env, " ", -1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb);
	if (env->conv.sharp == 1)
		ft_putinit(env, "0", -1);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!( env->conv.nb[0] == '0' && env->conv.precision > -1))
		ft_putinit(env, env->conv.nb, -1);
}

void			convo(va_list args, t_env *env)
{
	int		i;

	if (env->conv.conversion == 7)
		convitoabase(args, env, 8);
	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	if (env->conv.neg == 1)
	{
		if (env->conv.sharp == 1)
			ft_putinit(env, "0", -1);
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!( env->conv.nb[0] == '0' && env->conv.precision <= 0 &&
					env->conv.champ != 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convoplus(env);
}

void	convpercent(va_list args, t_env *env)
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
