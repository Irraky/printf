/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/03/22 16:23:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_features(t_env *env, char *format, int limit)
{
	while (++*format)
	{
	}
}

void	get_data(t_env *env, const char *format)
{
	int		i;
	int		j;
	char	*conversions;

	i = 1;
	j = -1;
	conversions = "SspDdiOoUuXxCc%";
	while (format[env->indexstr + i])
	{
		while (conversions[++j])
			if (format[env->indexstr + i] == conversions[j])
			{
				env->conversion = j;
				break;
			}
		if (env->conversion > 0)
			break;
		j = 0;
		i++;
	}
	if (env->conversion == -1)
		ft_exit("Pas d'argument de conversion", ERROR);
	//get_features(&env, &format[env->indexstr], i);
	env->indexstr = env->indexstr + i + 1;
}
