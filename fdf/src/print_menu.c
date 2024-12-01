/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:16 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/22 16:38:31 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_dot param)
{
	char	*menu;

	menu = "up, down, left, right for move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 5, 0xffffff, menu);
	menu = "5, spase for 3d/2d mode; +, - for zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 20, 0xffffff, menu);
	menu = "8, 2 for z-scale; 4, 6 for rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 35, 0xffffff, menu);
	menu = "f for full screen mode";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 50, 0xffffff, menu);
}
