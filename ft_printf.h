/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:01:02 by drecours          #+#    #+#             */
/*   Updated: 2017/03/20 16:29:47 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libftprintf/libft.h"

# define ERROR -1
# define FAILED_TO_MALLOC -26
# define BUFF_SIZE 1024

typedef struct			s_env
{
	int					indexstr;
	int					indexbuff;
	int					conversion;
	char				buffer[BUFF_SIZE];
	char				*flags;
}						t_env;

#endif
