/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/23 17:41:34 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_putinit(t_env *env, char *addit, int size)
{
	int		i;

	i = -1;
	while (addit[++i] && (i < size || size == -1))
	{
		env->buffer[env->indexbuff] = addit[i];
		if (env->indexbuff++ >= BUFF_SIZE)
		{
			ft_putstr((char const *)env->buffer);
			ft_bzero(&env->buffer, BUFF_SIZE);
			env->indexbuff = 0;
		}
	}
}

static void		ft_init_env(t_env *env)
{
	env->indexstr = 0;
	env->indexbuff = 0;
	env->conv.conversion = -1;
	ft_bzero(env->conv.flags, 4);
	ft_bzero(&env->buffer, BUFF_SIZE);
	ft_bzero(&env->conv.nb, 65);
}

/*static void		destroy_env(t_env *env)
  {
  ft_memdel((void **)&(env->buffer));
  ft_memdel((void **)&(env->flags));
  }*/

int				ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	int			i;

	i = 0;
	ft_init_env(&env);
	va_start(args, format);
	while (format[env.indexstr])
	{
		while (format[env.indexstr] != '%' && format[env.indexstr])
			++env.indexstr;
		ft_putinit(&env, (char *)&format[i], env.indexstr - i);
		if (format[env.indexstr] == '%')
		{
			get_data(&env, format);
			i = env.indexstr;
			/*tab_tconv[env.conv.conversion](args, &env);  //faire tableau pointeur sur fonction*/ //Non.
			env.conv.conversion = -1;
			///ft_cleanit struc conversion
		}
	}
	ft_putstr(env.buffer);
	va_end(args);
	return (0);
}

int		main(void)
{
	ft_printf("%viici une %qqqqqu de caractere% xtruc troc % hhhU \ncoincoini\n %drenw", 8, 12, 13, 24, 12);
	return (0);
}
