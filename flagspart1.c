/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagspart1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:25:00 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 23:07:01 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void			getchamp(t_env *env, const char *format)
{
	int		add;
	int		place;
	char	transit[11];

	add = 1;
	place = -1;
	while (env->i + add < env->indexstr - 1 && format[env->i + add] != '.')
	{
		if (format[env->i + add] == '-')
			env->conv.neg = 1;
		if (ft_isdigit(format[env->i + add]))
		{
			if (format[env->i + add] == '0')
				env->conv.zero = 1;
			while (ft_isdigit(format[env->i + add]))
			{
				transit[++place] = format[env->i + add];
				add++;
			}
			transit[place + 1] = '\0';
			env->conv.champ = ft_atoi(transit);
			break ;
		}
		add ++;
	}
}

void			getprecision(t_env *env, const char *format)
{
	int		add;
	int		place;
	char	transit[11];

	add = 1;
	place = -1;
	while (env->i + add < env->indexstr - 1)
	{
		if (format[env->i + add] == '.')
		{
			while (ft_isdigit(format[env->i + ++add]))
				transit[++place] = format[env->i + add];
			transit[place + 1] = '\0';
			env->conv.precision = ft_atoi(transit);
			break ;
		}
		add ++;
	}
}
