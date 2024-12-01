/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:30 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/26 17:02:03 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*get_prm(t_dot **matrix)
{
	return (&matrix[0][0]);
}

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.5;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 2.1;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	quitter(void)
{
	ft_printf("Quitting\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_dot	*prm;

	if (argc != 2)
		ft_error("Utilisation: ./fdf map.fdf");
	matrix = read_map(argv[1]);
	prm = get_prm(matrix);
	set_default(prm);
	draw(matrix);
	mlx_key_hook(prm->win_ptr, deal_key, matrix);
	mlx_hook(prm->win_ptr, 17, 0, quitter, matrix);
	mlx_loop(prm->mlx_ptr);
}
