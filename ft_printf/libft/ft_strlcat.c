/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:52 by mael-faq          #+#    #+#             */
/*   Updated: 2024/10/14 16:47:53 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	total_len;
	size_t	i;
	size_t	j;

	total_len = ft_strlen(src);
	if (dstsize != 0)
	{
		dstlen = ft_strlen(dst);
		dstsize -= 1;
		i = dstlen;
		j = 0;
		while (i < dstsize && src[j])
			dst[i++] = src[j++];
		if (dstsize + 1 > dstlen)
		{
			dst[i] = '\0';
			total_len += dstlen;
		}
		else
			total_len += dstsize + 1;
	}
	return (total_len);
}
