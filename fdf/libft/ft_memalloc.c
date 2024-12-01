/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:15:50 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:15:51 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *temp;

	temp = (char *)malloc(size);
	if (temp == NULL || size == 0)
		return (NULL);
	ft_bzero(temp, size);
	return ((void *)temp);
}
