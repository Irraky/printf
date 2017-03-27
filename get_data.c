/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 17:46:05 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**void	get_features(t_env *env, char *format, int limit)
**{
**	while (++*format)
**	{
**	}
**}
*/

void	get_data(t_env *env, const char *format)
{
	int			i;
	int			j;
	const char	*conversions = "SspDdiOoUuXxCc%";

	i = 1;
	j = -1;
	while (format[env->indexstr + i])
	{
		while (conversions[++j])
			if (format[env->indexstr + i] == conversions[j])
			{
				env->conv.conversion = j;
				break ;
			}
		if (env->conv.conversion > 0)
			break ;
		j = -1;
		i++;
	}
	if (env->conv.conversion < 0)
		ft_exit("\n Il manque un argument de conversion", ERROR);
	//get_features(&env, &format[env->indexstr], i);
	env->indexstr = env->indexstr + i + 1;
}
