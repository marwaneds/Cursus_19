/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:12:26 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/25 19:28:06 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_dot;

int				close_window(void *param);
t_dot			*get_prm(t_dot **matrix);
t_dot			**read_map(char *file_name);
void			isometric(t_dot *dot, double angle);
void			draw(t_dot **matrix);
int				deal_key(int key, t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void			new_window(int key, t_dot **matrix);

#endif