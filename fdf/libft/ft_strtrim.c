/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:41:47 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 20:41:48 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(char const *s)
{
	char const *p;

	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	p = s;
	while (*s != '\0')
		s++;
	if (p != s)
		s--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	return ((s - p) + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	str = ft_strsub(s, 0, length(s));
	return (str);
}
