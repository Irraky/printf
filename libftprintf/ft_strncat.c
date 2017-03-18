/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:18:29 by drecours          #+#    #+#             */
/*   Updated: 2017/01/04 18:56:57 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (s1[++i])
		;
	while (++j < n && s2[j])
	{
		s1[i] = s2[j];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
