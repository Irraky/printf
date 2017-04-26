/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:06:36 by drecours          #+#    #+#             */
/*   Updated: 2017/04/26 16:06:15 by drecours         ###   ########.fr       */
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
	if (env->wchar[0] != '\0')
		ft_putinit(env, env->wchar, -1);
	env->weight = (MB_CUR_MAX == 1 && args > 255) ? -1 : env->weight;
}

void			convgc(va_list arg, t_env *env)
{
	convc(arg, env);
}

void			convgs(va_list args, t_env *env)
{
	const wchar_t *s = va_arg(args, wchar_t *);
	
	if (s == (wchar_t *)NULL)
		ft_putinit(env, "(null)", -1);
	if (s)
	{
		while (*s)
			trick(*s++, env);
		return ;
	}
}
