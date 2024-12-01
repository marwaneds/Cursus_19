/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:12:48 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:12:49 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void	arr_copy(int *new, int *arr)
{
	int i;

	i = 0;
	while (i <= ARR_LEN)
	{
		new[i] = arr[i];
		i++;
	}
}

void	arr_cat(int **arr, char *addon)
{
	int		*new;
	char	**tmp;
	int		len;
	int		i;
	int		j;

	tmp = ft_split(addon, ' ');
	len = ft_arraylen(tmp);
	new = (int *)malloc(sizeof(int) * (len + *ARR_LEN + 1));
	arr_copy(new, *arr);
	new[0] += len;
	i = *ARR_LEN + 1;
	j = 0;
	while (tmp[j])
	{
		if (check_arr_input(tmp[j]))
		{
			j++;
			new[0]--;
			continue ;
		}
		new[i] = ft_atoi(tmp[j]);
		i++;
		j++;
	}
	free(*arr);
	ft_arrayfree(tmp);
	*arr = new;
}
