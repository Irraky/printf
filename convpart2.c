/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:54:51 by drecours          #+#    #+#             */
/*   Updated: 2017/04/28 17:36:20 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		putnwchar(const wchar_t *str, t_env *env)
{
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	env->conv.precision = (env->conv.precision == -1) ? ft_wstrlen(str) :
		env->conv.precision;
	while (str[i] && printed + ft_wcsize(str[i]) <= env->conv.precision)
	{
		printed += ft_wcsize(str[i]);
		trick(str[i], env);
		i ++;
	}
}

void			convgs(va_list args, t_env *env)
{
	const wchar_t		*str = va_arg(args, wchar_t *);
	int			i;
	int			j;

	if (str == (wchar_t *)NULL)
		ft_putinit(env, "(null)", -1);
	else
	{
		j = -1;
		i = (env->conv.precision > ft_wstrlen(str)) ? (env->conv.champ -
				ft_wstrlen(str)) : (env->conv.champ - env->conv.precision);
		i = (env->conv.precision < 0) ? env->conv.champ - ft_wstrlen(str) : i;
		if (env->conv.neg == 1)
		{
			putnwchar(str, env);
			while (++j < i)
				ft_putinit(env, " ", -1);
		}
		else
		{
			while (++j < i)
				ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
			putnwchar(str, env);
		}
	}
}

void			convgc(va_list args, t_env *env)
{
	int		i;
	const wchar_t	 s = va_arg(args, wchar_t);
	const int	j = ft_wcsize(s);

	i = -1;
	if (s)
	{
	if (s == 0 && env->conv.champ != -1 && env->conv.zero == 1)
		env->conv.champ++;
		if (env->conv.neg == 1)
		{
			trick(s, env);
			while (++i < env->conv.champ - j)
				ft_putinit(env, " ", -1);
		}
		else
		{
			while (++i < env->conv.champ - j)
				ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
			trick(s, env);
		}
	}
	else
		env->weight++;
}

static void			convoplus(t_env *env)
{
	int		i;

	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	if (env->conv.nb[0] == '0' && env->conv.sharp == 1)
		i--;
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
	if (env->conv.sharp == 1)
		ft_putinit(env, "0", -1);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!(env->conv.sharp == 1 && env->conv.nb[0] == '0') &&
			!(env->conv.precision == 0 && env->conv.nb[0] == '0'))
		ft_putinit(env, env->conv.nb, -1);
}

void			convo(va_list args, t_env *env)
{
	int		i;

	if (env->conv.conversion == 7)
		convitoabase(args, env, 8);
	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	if (env->conv.nb[0] == '0')
		i++;
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
