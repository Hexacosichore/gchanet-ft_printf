/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:08:07 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/04 07:12:24 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include "stdio.h"

void	ft_print_int(int val, t_va_opt opt)
{
	int				sign;

	(void) opt;
	if (opt.len > 0)
	{
		sign = -1 + ((val >= 0) * 2);
		while (!opt.flag_dash && !opt.flag_zero
			&& !opt.flag_ptn && opt.len-- > ft_nbrlen(val))
			ft_putchar_fd(' ', 1);
		if (opt.flag_ptn || opt.flag_zero)
		{
			if (sign == -1)
			{
				ft_putchar_fd('-', 1);
				val *= -1;
				if (!opt.flag_ptn)
					opt.len--;
			}
			while (opt.len-- > ft_nbrlen(val))
				ft_putchar_fd('0', 1);
		}
		ft_putnbr_fd(val, 1);
		while (opt.flag_dash && opt.len-- > ft_nbrlen(val))
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putnbr_fd(val, 1);
}

void	ft_print_unsigned_int(int val, t_va_opt opt)
{
	(void) opt;
	ft_putnbr_fd(val, 1);
}

void	ft_print_char(char val, t_va_opt opt)
{
	(void) opt;
	ft_putchar_fd(val, 1);
}

void	ft_print_char_ptr(char *val, t_va_opt opt)
{
	(void) opt;
	if (opt.len == 0)
		ft_putstr_fd(val, 1);
	else
	{
		while (opt.len--)
			ft_putchar_fd(*val++, 1);
	}
}

void	ft_print_unsigned_long(unsigned long val, t_va_opt opt)
{
	(void) opt;
	ft_putnbr_fd(val, 1);
}

int	ft_check_flags(t_printf	*ptf)
{
	while (1)
	{
		if (*ptf->f == '.')
			ptf->opt.flag_ptn = 1;
		else if (*ptf->f == '-')
			ptf->opt.flag_dash = 1;
		else if (*ptf->f == '0')
			ptf->opt.flag_zero = 1;
		else if (*ptf->f == '*')
			return (0);
		else if (*ptf->f >= '0' && *ptf->f <= '9')
		{
			ptf->opt.len = ft_atoi(ptf->f);
			while (*(ptf->f + 1) >= '0' && *(ptf->f + 1) <= '9')
				ptf->f++;
		}
		else
			break ;
		ptf->f++;
	}
	return (1);
}

void	ft_check_conv(t_printf	*ptf)
{
	while (1)
	{
		if (*ptf->f == 'c')
			ft_print_int(va_arg(ptf->ap, int), ptf->opt);
		else if (*ptf->f == 's')
			ft_print_char_ptr(va_arg(ptf->ap, char *), ptf->opt);
		else if (*ptf->f == 'p') /* p = va_arg(args, unsigned long )# ou #(unsigned long)va_arg(args, void *); */
			ft_print_unsigned_long(va_arg(ptf->ap, unsigned long), ptf->opt);
		else if (*ptf->f == 'd')
			ft_print_int((int) va_arg(ptf->ap, int), ptf->opt);
		else if (*ptf->f == 'i')
			ft_print_int(va_arg(ptf->ap, int), ptf->opt);
		else if (*ptf->f == 'u')
			ft_print_unsigned_int(va_arg(ptf->ap, unsigned int), ptf->opt);
		else if (*ptf->f == 'x')
			ft_print_unsigned_int(va_arg(ptf->ap, unsigned int), ptf->opt);
		else if (*ptf->f == 'X')
			ft_print_unsigned_int(va_arg(ptf->ap, unsigned int), ptf->opt);
		else if (*ptf->f != '%')
			break ;
		ptf->f++;
	}
}

void	init_opt(t_va_opt *opt)
{
	opt->flag_ast = 0;
	opt->flag_dash = 0;
	opt->flag_ptn = 0;
	opt->flag_zero = 0;
	opt->len = 0;
}

int	ft_printf(const char *format, ...)
{
	t_printf	*ptf;

	ptf = (t_printf *)malloc(sizeof(t_printf));
	if (!ptf)
		return (-1);
	ptf->f = (char *)format;
	va_start(ptf->ap, format);
	while (*ptf->f)
	{
		if (*ptf->f == '%')
		{
			ptf->f++;
			init_opt(&ptf->opt);
			if (ft_check_flags(ptf))
				ft_check_conv(ptf);
		}
		else
		{
			write(1, ptf->f, 1);
			ptf->f++;
		}
	}
	va_end(ptf->ap);
	return (1);
}
