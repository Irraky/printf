/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:36:48 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 18:25:39 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			convu(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convi(va_list args, t_env *env)
{
	ft_itoa(va_arg(args, signed int), env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convx(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convgu(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long unsigned int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void			convd(va_list args, t_env *env)
{
	ft_itoa(va_arg(args, signed int), env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}
