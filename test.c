/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:40:51 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/04 07:34:43 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("ft_printf   Hello %-6s %.7s \n", "worls at war", "test");
	printf("   printf   Hello %-6s %.7s \n\n", "worls at war", "test");

	ft_printf("ft_printf   Hello %.4s %.3s \n", "worls at war", "test");
	printf("   printf   Hello %.4s %.3s \n\n", "worls at war", "test");

	ft_printf("ft_printf   Hello %.4s %.1s \n", "worls at war", "test");
	printf("   printf   Hello %.4s %.1s \n\n", "worls at war", "test");

	ft_printf("ft_printf   Hello %6s %.s \n", "worls at war", "test");
	printf("   printf   Hello %6s %.s \n\n", "worls at war", "test");
}
