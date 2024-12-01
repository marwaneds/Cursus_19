/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:07 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:08 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void	arr_print(int *arr)
{
	int i;

	i = 1;
	while (i <= ARR_LEN)
	{
		ft_printf("%d ", arr[i++]);
	}
	ft_printf("\n");
}