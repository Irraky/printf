/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:23:00 by drecours          #+#    #+#             */
/*   Updated: 2017/01/06 15:28:33 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}
