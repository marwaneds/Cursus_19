/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:41 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/26 17:01:23 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_win_size(int key, t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	if ((key == 0 && prm->win_y <= 500) || (key == 6 && prm->win_x <= 500))
		return (1);
	if ((key == 1 && prm->win_y > 1000) || (key == 7 && prm->win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_dot **matrix)
{
	static int	old_x;
	static int	old_y;
	t_dot		*prm;

	prm = get_prm(matrix);
	if (prm->win_x != 2560)
	{
		old_x = prm->win_x;
		old_y = prm->win_y;
	}
	if (prm->win_x == 2560)
		prm->win_x = old_x;
	else
		prm->win_x = 2560;
	if (prm->win_y == 1400)
		prm->win_y = old_y;
	else
		prm->win_y = 1400;
}

void	change_window_size(int key, t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		prm->win_x -= 100;
	if (key == 7)
		prm->win_x += 100;
	if (key == 0)
		prm->win_y -= 100;
	if (key == 1)
		prm->win_y += 100;
	if (key == 3)
		full_screen(matrix);
}

void	new_window(int key, t_dot **matrix)
{
	t_dot	*prm;

	prm = get_prm(matrix);
	change_window_size(key, matrix);
	mlx_destroy_window(prm->mlx_ptr, prm->win_ptr);
	prm->mlx_ptr = mlx_init();
	prm->win_ptr = mlx_new_window(prm->mlx_ptr, prm->win_x, prm->win_y, "FDF");
	prm->shift_x = prm->win_x / 3;
	prm->shift_y = prm->win_y / 3;
	draw(matrix);
	mlx_key_hook(prm->win_ptr, deal_key, matrix);
	mlx_loop(prm->mlx_ptr);
}
