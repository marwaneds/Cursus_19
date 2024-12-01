/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_redactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:54 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:55 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_redactor(char *arg, register t_flag flags)
{
	char	*str;
	int		len;

	len = ft_strlen_color(arg);
	if (flags.width != -1 && flags.width < len && flags.spcf != '%')
	{
		arg[flags.width] = '\0';
		len = flags.width;
	}
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		arg = (flags.minus) ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
	}
	return (arg);
}

int		ft_strlen_color(char *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '{')
			{
				s += color_redactor(&s[i]);
				if (!s[i])
					break ;
			}
			i++;
		}
	return (i);
}

int		putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
				ft_putchar('^');
			ft_putchar(s[i++]);
		}
	return (i);
}

int		putstr_color(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '{')
			{
				i += color_redactor(&s[i]);
				if (!s[i])
					break ;
			}
			ft_putchar(s[i++]);
		}
	return (i);
}
