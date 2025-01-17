/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:43 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:44 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

typedef struct
{
	short			width;
	unsigned short	length;
	unsigned short	steps;
	unsigned char	spcf;
	unsigned char	filler;
	unsigned char	hashtag;
	unsigned char	minus;
	unsigned char	spase;
	unsigned char	plus;
	unsigned char	zero;
	unsigned char	l_flag;
	unsigned char	ld_flag;
	unsigned char	h_flag;
	unsigned char	j_flag;
	unsigned char	z_flag;
}					t_flag;

t_flag			flag_analazer(const char *s);
char			*specifier(t_flag *flags, va_list *ap);
char			*redactor(char *arg, t_flag flags, register char spcf);
char			*str_redactor(char *arg, register t_flag flags);
int				color_redactor(const char *str);
int				putstr_for_null_char(char *s);
int				putstr_color(char *s);
int				ft_strlen_color(char *s);

#endif
