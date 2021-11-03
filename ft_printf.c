/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:08:07 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/03 10:08:07 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

typedef struct s_printf
{
	va_list	ap;

	int	flag_ptn:1; 		/* . */
	int	flag_dash:1;		/* - */
	int	flag_ast:1;			/* * */
	int	flag_zero:1;		/* 0 */

	int	conv_c:1;
	int	conv_s:1;
	int	conv_p:1;
	int	conv_d:1;
	int	conv_d:1;
}			t_printf;

int	ft_printf(const char *format, ...)
{
	int			pos;
	t_printf	*ptf;

	pos = 0;
	*ptf = (t_printf *)ft_memalloc(sizeof(t_printf));
	if (!ptf)
		return (-1);
	va_start(ptf->ap, format);
	while (format[pos])
	{
	   if (format[pos] == '%')
	   {
			if (format[pos] == '.')
			{
				tab->pnt = 1; 
				pos++;
			}  
			if (format[pos] == '-') 
				tab->dash = 1; 
			if (format[pos] == 'c') 
				ft_print_char(tab); 
			if (format[pos] == 'd' || format[pos] == 'i') 
				ft_print_integer(tab); 
				pos++; 
	   }
	   else
	   {
		   ft_putchar(format[pos]);
	   }
	   pos++;
   }
   va_end(ptf->ap);
}
/*
c = va_arg(args, int) 
s = va_arg(args, char *) 
d = va_arg(args, int) 
i = va_arg(args, int) 
u = va_arg(args, unsigned int) 
p = va_arg(args, unsigned long )# ou 
                               #(unsigned long)va_arg(args, void *); 
x = va_arg(args, entier non signé) 
X = va_arg(args, entier non signé)
*/

//https://csnotes.medium.com/ft-printf-tutorial-42project-f09b6dc1cd0e