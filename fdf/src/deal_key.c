/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:38 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/27 15:54:33 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22 || key == 17);
}

int	is_isometric1(t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	if (prm->is_isometric)
		return (0);
	else
		return (1);
}

void	do_key(int key, t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	if (key == 24 || key == 69)
		prm->scale += 3;
	if (key == 27 || key == 78)
		prm->scale -= 3;
	if (key == 91 || key == 28)
		prm->z_scale += 1;
	if (key == 84 || key == 19)
		prm->z_scale -= 1;
	if (key == '~')
		prm->shift_y -= 10;
	if (key == '}')
		prm->shift_y += 10;
	if (key == '{')
		prm->shift_x -= 10;
	if (key == '|')
		prm->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		prm->is_isometric = is_isometric1(matrix);
	if (key == 86 || key == 21)
		prm->angle += 0.05;
	if (key == 88 || key == 22)
		prm->angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	if (is_key(key))
	{
		mlx_clear_window(prm->mlx_ptr, prm->win_ptr);
		do_key(key, matrix);
		print_menu(*prm);
		draw(matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
	{
		mlx_destroy_window(prm->mlx_ptr, prm->win_ptr);
		free(matrix);
		ft_printf("Quitting\n");
		exit(0);
	}
	return (0);
}
