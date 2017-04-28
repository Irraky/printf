/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/04/28 17:39:58 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include<stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int		main(void)
{
	int	i;

	i = 1;
	setlocale(LC_ALL, "en_US.UTF-8");
//	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", 
//			L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
//	printf("i%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", 
//			L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	//printf("\n|valeur printf: %d|\n", printf("%c", L'a'));
	//printf("%d", MB_CUR_MAX);
	//printf("\n|valeur ft_printf: %d|\n", ft_printf("\n|%lc|", L'暖'));
	//ft_printf("{%}");
	// printf("|%*.*d|\n", 7, 2, );
	 //ft_printf("|%*.*d|", 7);
	//printf("printf : |%D|\n", LONG_MAX);
	//printf("ft_printf : |%li|\n", LONG_MAX);
	//ft_printf("|%sv|\n", "a");
	//ft_printf("{%*d}", 0, 0);
	//ft_printf("{%*s}", "test", 0);
	//ft_printf("{%*d}", 0, 0);
	//ft_printf("{%*s}", "test", 0);
	//printf("{%3*d}", 0, 0);
	//printf("pf: %d\n", printf("{%3c}\n", 0));
	//ft_printf("pf: %d\n", printf("{%3c}\n", 0));
	//printf("pf: %d\n", ft_printf("%c", 201));
	//printf("pf: %d\n", printf("%c", 201));
	  printf("{%3c}", 0);
      ft_printf("{%3c}", 0);

	return 0;
}
