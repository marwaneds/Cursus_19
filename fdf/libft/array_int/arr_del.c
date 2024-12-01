/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:12:52 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:12:53 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static void	del_nbr(int *arr, int index)
{
	if (index < ARR_LEN && index >= 0)
	{
		index++;
		while (index < ARR_LEN)
		{
			arr[index] = arr[index + 1];
			index++;
		}
		ARR_LEN--;
	}
}

void		arr_del(int *arr, int index, ...)
{
	va_list	ap;
	int		ind;
	int		i;

	va_start(ap, index);
	del_nbr(arr, index);
	i = 1;
	while ((ind = va_arg(ap, int)))
	{
		del_nbr(arr, ind - i);
		i++;
	}
	va_end(ap);
}
