/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:14 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:15 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H
# define ARR_LEN arr[0]

#include "../libft.h"

int		*arr_new(char *arr);
int		arr_len(int *arr);
int		arr_get(int *arr, int index);
void	arr_set(int *arr, int index, int nbr);
void	arr_del(int *arr, int index, ...);
void	arr_print(int *arr);
void	arr_add(int **arr, int index, int nbr);
void	arr_cat(int **arr, char *addon);

int		check_arr_input(char *nbr);
void	arr_copy(int *new, int *arr);

#endif