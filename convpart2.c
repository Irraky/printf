/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:54:51 by drecours          #+#    #+#             */
/*   Updated: 2017/03/25 13:28:01 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convstr(va_list args, t_env *env)
{
	ft_putinit(env, va_arg(args, char *), -1);
}


void	convc(va_list args, t_env *env)
{
	ft_putinit(env, va_arg(args, char *), 1);
}

void	convgd(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, long int), 10, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

void	convo(va_list args, t_env *env)
{
	ft_itoa_base(va_arg(args, unsigned int), 8, env->conv.nb);
	ft_putinit(env, env->conv.nb, -1);
}

