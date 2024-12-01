/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:34 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/25 18:30:50 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	mlx_put_pixel_image(t_dot a, t_dot *param, int color)
{
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	if (b.z || a.z)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if (b.z != a.z)
		color = 0xfc031c;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_put_pixel_image(a, param, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;
	t_dot	*prm;

	prm = get_prm(matrix);
	print_menu(*prm);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], prm);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], prm);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
