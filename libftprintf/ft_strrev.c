/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:21:53 by drecours          #+#    #+#             */
/*   Updated: 2017/03/18 15:05:09 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s1)
{
	char	*s2;
	int		i;
	int		j;

	if (!*s1 || !s1)
		return (NULL);
	if (!(s2 = (char*)malloc((char)sizeof ft_strlen(s1) + 1)))
		return (NULL);
	j = 0;
	i = ft_strlen(s1) - 1;
	while (s1[j])
	{
		s2[i] = s1[j];
		j++;
		i--;
	}
	return (s2);
}
