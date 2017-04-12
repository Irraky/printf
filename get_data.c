/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/04/12 11:44:03 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>


void	get_features(t_env *env, const char *format)
{
	getchamp(env, format);
	getprecision(env, format);
	littleflags(env, format);
}


void	get_data(t_env *env, const char *format)
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
			{
				if ((j == 11 || j == 13 || j == 7 || j == 9 || j == 4 || j == 1)
						&& format[env->indexstr + i - 1] == 'l')
					env->conv.conversion = j - 1;
				else
					env->conv.conversion = j;
				break ;
			}
		if (env->conv.conversion > 0)
			break ;
		j = -1;
		i++;
	}
	env->indexstr = env->indexstr + i + 1;
	get_features(env, format);
}
