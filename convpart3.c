/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:06:36 by drecours          #+#    #+#             */
/*   Updated: 2017/05/11 14:30:07 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdio.h>


void			trick(wchar_t args, t_env *env)
{
	ft_bzero(&env->wchar, 5);
	if ((unsigned)args < 0x80)
		env->wchar[0] = args;
	else if ((unsigned)args <= 0x800)
	{
		env->wchar[0] = ((args >> 6) + 0xC0);
		env->wchar[1] = ((args & 0x3F) + 0x80);
	}
	else if ((unsigned)args <= 0xd800 || (unsigned)args - 0xE000 < 0x2000)
	{
		env->wchar[0] = ((args >> 12) + 0xE0);
		env->wchar[1] = (((args >> 6) & 0x3F) + 0x80);
		env->wchar[2] = ((args & 0x3F) + 0x80);
	}
	else if ((unsigned)args - 0x10000 < 0x100000)
	{
		env->wchar[0] = ((args >> 18) + 0xF0);
		env->wchar[1] = (((args >> 12) & 0x3F) + 0x80);
		env->wchar[2] = (((args >> 6) & 0x3F) + 0x80);
		env->wchar[3] = ((args & 0x3F) + 0x80);
	}
	ft_putinit(env, env->wchar, -1);
	if (!env->wchar[0])
		ft_putinit(env, "\0", 1);
	env->weight = (MB_CUR_MAX == 1 && args > 255) ? -1 : env->weight;
}

void			convc(va_list arg, t_env *env)
{
	convgc(arg, env);
}

void			convs(va_list args, t_env *env)
{
	char	*str;
	int		i;
	int		j;

	if (env->l == 1)
		convgs(args, env);
	else
		str = va_arg(args, char *);
	if (env->l == 0 && !str)
		ft_putinit(env, "(null)", -1);
	else if (env->l == 0 && str)
	{
		j = -1;
		i = (env->conv.precision > (int)ft_strlen(str)) ? (env->conv.champ -
				(int)ft_strlen(str)) : (env->conv.champ - env->conv.precision);
		i = (env->conv.precision < 0) ? env->conv.champ - ft_strlen(str) : i;
		if (env->conv.neg == 1)
		{
			ft_putinit(env, (char *)str, (env->conv.precision != -1) ?
					env->conv.precision : (int)ft_strlen(str));
			while (++j < i)
				ft_putinit(env, " ", -1);
		}
		else
		{
			while (++j < i)
				ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
			ft_putinit(env, (char *)str, (env->conv.precision != -1) ?
					env->conv.precision : (int)ft_strlen(str));
		}
	}
}

void			convpercent(va_list args, t_env *env)
{
	int	i;

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
