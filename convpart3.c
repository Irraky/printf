/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:06:36 by drecours          #+#    #+#             */
/*   Updated: 2017/04/22 17:04:12 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

static void			trick(wchar_t args, t_env *env)
{
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
}

void			convgc(va_list arg, t_env *env)
{
	trick(va_arg(arg, wchar_t), env);
}

void			convgs(va_list args, t_env *env)
{
	wchar_t	*s;

	s = va_arg(args, wchar_t *);
	while (s && *s)
	{
		trick(*s, env);
		s++;
	}
}
