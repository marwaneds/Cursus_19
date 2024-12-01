/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:10 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:11 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void		arr_set(int *arr, int index, int nbr)
{
	if (index < ARR_LEN && index >= 0)
		arr[index + 1] = nbr;
}