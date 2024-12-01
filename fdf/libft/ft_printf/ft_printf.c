/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:39 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:40 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	flags;
	char	*s;
	int		total;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		format += (*format == '{') ? color_redactor(format) : 0;
		if (*format != '%' && *format)
		{
			ft_putchar(*format++);
			total++;
			continue ;
		}
		flags = (*format) ? flag_analazer(++format) : flag_analazer(format);
		if (!(s = specifier(&flags, &ap)))
			continue ;
		format += flags.steps;
		total += putstr_color(s);
		ft_strdel(&s);
	}
	va_end(ap);
	return (total);
}
