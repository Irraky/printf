/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:36:48 by drecours          #+#    #+#             */
/*   Updated: 2017/03/25 12:39:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convnbu(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convnbi(va_list args, t_env *env)
{
	ft_itoa(va_arg(args, signed int), env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convnbgx(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 16, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convnbgu(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long unsigned int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convnbd(va_list args, t_env *env)
{
	ft_itoa(va_arg(args, signed int), env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}
