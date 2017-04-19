/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:06:36 by drecours          #+#    #+#             */
/*   Updated: 2017/04/19 18:23:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			convgc(va_list args, t_env *env)
{
	if (va_arg(args, wchar_t) <= 0x7F)
		ft_putinit(env, va_arg(args, char*), -1);
	else if (va_arg(args, wchar_t) <= 0x7FF)
	{
		env->wchar[0] = (va_arg(args, wchar_t) >> 6) + 0xC0;
		env->wchar[1] = (va_arg(args, wchar_t) & 0x3F) + 0x80;
	}
	else if (va_arg(args, wchar_t) <= 0xFFFF)
	{
		env->wchar[0] = (va_arg(args, wchar_t) >> 12) + 0xE0;
		env->wchar[1] = ((va_arg(args, wchar_t) >> 6) & 0x3F)+ 0x80;
		env->wchar[2] = (va_arg(args, wchar_t) & 0x3F) + 0x80;
	}
	else if (va_arg(args, wchar_t) <= 0x10FFFF)
	{
		env->wchar[0] = (va_arg(args, wchar_t) >> 18) + 0xF0;
		env->wchar[1] = ((va_arg(args, wchar_t) >> 12) & 0x3F) + 0x80;
		env->wchar[2] = ((va_arg(args, wchar_t) >> 6) & 0x3F) + 0x80;
		env->wchar[3] = (va_arg(args, wchar_t) & 0x3F) + 0x80;
	}
	if (va_arg(args, wchar_t) <= 0x10FFFF && va_arg(args, wchar_t) > 0x7f)
		ft_putinit(env, env->wchar, -1);
}

void			convgs(va_list args, t_env *env)
{
	(void)args;
	(void)env;
}
