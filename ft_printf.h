/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:07:53 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/04 07:07:16 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_va_opt
{
	int				flag_ptn:1;
	int				flag_dash:1;
	int				flag_ast:1;
	int				flag_zero:1;
	int				len;
	unsigned int	lennbr;
}			t_va_opt;

typedef struct s_printf
{
	char			*f;
	va_list			ap;
	t_va_opt		opt;
}			t_printf;

/*	utils	*/
int	ft_nbrlen(int nbr);

#endif