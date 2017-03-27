/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:26:29 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 12:05:44 by drecours         ###   ########.fr       */
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
	ft_bzero(&env->conv.flags, 4);
	ft_bzero(&env->buffer, BUFF_SIZE);
	ft_bzero(&env->conv.nb, 65);
}

/*static void		destroy_env(t_env *env)
  {
  ft_memdel((void **)&(env->buffer));
  ft_memdel((void **)&(env->flags));
  }*/

void			cleanit(t_env *env)
{
	env->conv.conversion = -1;
	ft_bzero(&env->conv.nb, 65);
	ft_bzero(&env->conv.flags, 4);
	
}

int				ft_printf(const char *format, ...)
{
	t_env		env;
	va_list		args;
	int			i; 
	const tconv tab_conv[] = {convgs, convs, convp, convgd, convd, convi, convgo,
	convo, convgu, convu, convgx, convx, convgc, convc};

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
			//printf("\ntest : %d\n", env.conv.conversion);
			tab_conv[env.conv.conversion](args, &env);
			cleanit(&env);
		}
	}
	ft_putstr(env.buffer);
	va_end(args);
	return (0);
}

int		main(void)
{
	int		d;
	d = 27;
	ft_printf("i%u %ud iiu", 8, 12, 13, 24, 12);
	return (0);
}
