/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:01:02 by drecours          #+#    #+#             */
/*   Updated: 2017/03/23 17:41:20 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libftprintf/libft.h"

# define ERROR -1
# define FAILED_TO_MALLOC -26
# define BUFF_SIZE 1024

typedef struct			s_conversion_pourcent
{
	int					conversion;
	char				nb[65];
	char				*flags[4];
}						t_conversion_pourcent;

typedef struct			s_env
{
	int						indexstr;
	int						indexbuff;
	char					buffer[BUFF_SIZE];
	t_conversion_pourcent	conv;
}						t_env;

void					ft_putinit(t_env *env, char *addit, int size);
void					get_data(t_env *env, const char *format);

/*
**CONVERSIONS
*/
void					convnbu(va_list arg, t_env *env);
void					convnbgu(va_list arg, t_env *env);
void					convnbi(va_list arg, t_env *env);
void					convnbd(va_list arg, t_env *env);
void					convnbgx(va_list arg, t_env *env);

/*typedef void			(*tconv)(va_list arg, t_env *env);
tconv	tab_tconv[6] = {convnbu, convnbgu, convnbi, convnbd, convnbgx
};*/    //BORDEL faux
#endif
