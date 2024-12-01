/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:42 by mael-faq          #+#    #+#             */
/*   Updated: 2024/10/14 16:45:43 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (0);
	calloc = malloc(size * count);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, count * size);
	return (calloc);
}
