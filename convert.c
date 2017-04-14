/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:02:52 by drecours          #+#    #+#             */
/*   Updated: 2017/04/14 11:39:49 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convitoabase(va_list args, t_env *env, int base)
{
	int		i;

	i = -1;
	if (env->hh == 1)
		ft_itoa_base((unsigned char)va_arg(args, int), base, env->conv.nbp);
	if (env->h == 1)
		ft_itoa_base((unsigned short)va_arg(args, unsigned), base, env->conv.nbp);
	 if (env->l == 1 || env->conv.conversion == 3)
		ft_itoa_base(va_arg(args, unsigned long), base, env->conv.nbp);
	else if (env->ll == 1)
		ft_itoa_base(va_arg(args, unsigned long long), base, env->conv.nbp);
	else if (env->j == 1)
		ft_itoa_base(va_arg(args, uintmax_t), base, env->conv.nbp);
	else if (env->z == 1)
		ft_itoa_base(va_arg(args, size_t), base, env->conv.nbp);
	else
		ft_itoa_base(va_arg(args, unsigned int), base, env->conv.nbp);
	while (env->conv.nbp[++i])
		if (env->conv.nbp[i] <= 'z' && env->conv.nbp[i] >= 'a' &&
				env->conv.conversion == 10)
			env->conv.nb[i] = env->conv.nbp[i] - 32;
		else
			env->conv.nb[i] = env->conv.nbp[i];
}

void	convitoa(va_list args, t_env *env)
{
	if (env->hh == 1)
		ft_itoa((char)(va_arg(args, int)), env->conv.nb);
	if (env->h == 1)
		ft_itoa((short)(va_arg(args, int)), env->conv.nb);
	if (env->l == 1)
		ft_itoa(va_arg(args, long), env->conv.nb);
	else if (env->ll == 1)
		ft_itoa(va_arg(args, long long), env->conv.nb);
	else if (env->j == 1)
		ft_itoa(va_arg(args, intmax_t), env->conv.nb);
	else if (env->z == 1)
		ft_itoa(va_arg(args, size_t),  env->conv.nb);
	else
		ft_itoa(va_arg(args, int), env->conv.nb);
}
