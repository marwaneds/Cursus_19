/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:09 by mael-faq          #+#    #+#             */
/*   Updated: 2024/10/14 16:47:10 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstc;
	char	*srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	if (dst == src)
		return (dst);
	if (srcc < dstc)
	{
		while (len--)
			*(dstc + len) = *(srcc + len);
		return (dst);
	}
	while (len--)
		*dstc++ = *srcc++;
	return (dst);
}
