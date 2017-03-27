/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:01:02 by drecours          #+#    #+#             */
/*   Updated: 2017/03/27 15:51:51 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

# define ERROR -1
# define FAILED_TO_MALLOC -26
# define BUFF_SIZE 1024

typedef struct			s_conversion_pourcent
{
	int					conversion;
	char				nb[65];
	char				nbp[65];
	char				flags[4];
}						t_conversion_pourcent;

typedef struct			s_env
{
	int						indexstr;
	int						indexbuff;
	int						weight;
	char					buffer[BUFF_SIZE];
	t_conversion_pourcent	conv;
}						t_env;

int						ft_printf(const char *format, ...);
void					ft_putinit(t_env *env, char *addit, int size);
void					get_data(t_env *env, const char *format);
typedef void			(*tconv)(va_list arg, t_env *env);

/*
**CONVERSIONS
*/
void					convgs(va_list arg, t_env *env);
void					convs(va_list arg, t_env *env);
void					convp(va_list arg, t_env *env);
void					convgd(va_list arg, t_env *env);
void					convd(va_list arg, t_env *env);
void					convi(va_list arg, t_env *env);
void					convgo(va_list arg, t_env *env);
void					convo(va_list arg, t_env *env);
void					convgu(va_list arg, t_env *env);
void					convu(va_list arg, t_env *env);
void					convgx(va_list arg, t_env *env);
void					convx(va_list arg, t_env *env);
void					convgc(va_list arg, t_env *env);
void					convc(va_list arg, t_env *env);
void					convpercent(va_list arg, t_env *env);

/*
**LIBFT
*/
int						atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					ft_exit(char *s, int status);
int						ft_ilen(int n);
void					ft_itoa(int n, char *nb);
void					ft_itoa_base(unsigned long long num, unsigned long long
						base, char *nb);
void					ft_putchar(char c);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcpy(char *dst, const char *src);
size_t					ft_strlen(const char *s);
int						ft_toupper(int c);

#endif