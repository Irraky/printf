/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/04/15 18:02:13 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	if (format[env->indexstr + i - 1] == 'l')
	{
		if (format[env->indexstr + i - 2] == 'l')
			env->ll = 1;
		else 
			env->l = 1;
	}
	if (format[env->indexstr + i - 1] == 'h')
	{
		if (format[env->indexstr + i - 2] == 'h')
			env->hh = 1;
		else 
			env->h = 1;
	}
	if (format[env->indexstr + i - 1] == 'j')
		env->j = 1;
	if (format[env->indexstr + i - 1] == 'z')
		env->z = 1;
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
	if (env->conv.conversion == 15)
		env->indexstr = env->indexstr + 1;
	get_features(env, format, i);
}
