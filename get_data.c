/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/04/13 19:51:10 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>


void	vide(va_list args, t_env *env)
{
	(void)args;
	(void)env;
}

static void		get_features(t_env *env, const char *format, int i)
{
	env->indexstr = env->indexstr + i + 1;
	getchamp(env, format);
	getprecision(env, format);
	littleflags(env, format);
}

static int		get_conv(t_env *env, int j, int i, const char *format)
{
		env->conv.conversion = j;
	if ((j == 11 || j == 13 || j == 7 || j == 9 || j == 4 || j == 1)
			&& format[env->indexstr + i - 1] == 'l')
	{
		if (format[env->indexstr + i - 2] == 'l')
			env->l = 1;
		else 
			env->ll = 1;
	}
	if ((j == 11 || j == 13 || j == 7 || j == 9 || j == 4 || j == 1)
			&& format[env->indexstr + i - 1] == 'h')
	{
		if (format[env->indexstr + i - 2] == 'h')
			env->h = 1;
		else 
			env->hh = 1;
	}
	if ((j == 5 || j == 4 || j == 3) && format[env->indexstr + i - 1] == 'j')
		env->j = 1;
	if ((j == 11 || j == 13 || j == 7 || j == 9 || j == 4 || j == 1)
			&& format[env->indexstr + i - 1] == 'z')
		env->z = 1;
	env->conv.conversion = j;
	return (1);
}

void			get_data(t_env *env, const char *format)
{
	int			i;
	int			j;
	const char	*conversions = "SspDdiOoUuXxCc%";

	i = 1;
	j = -1;
	env->i = env->indexstr;
	while (format[env->indexstr + i])
	{
		while (conversions[++j])
			if (format[env->indexstr + i] == conversions[j])
				if (get_conv(env, j, i, format))
					break ;
		if (env->conv.conversion > 0)
			break ;
		j = -1;
		i++;
	}
	if (env->conv.conversion == -1)
		env->conv.conversion = 15;
	get_features(env, format, i);
}
