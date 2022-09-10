/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:22:48 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:20:23 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**data;
	int		offset_x;
	int		offset_y;
	int		rows;
	int		cols;
	int		x;
	int		y;
	int		z;
	float	angle;
	int		x_iso;
	int		y_iso;
	int		delta_x;
	int		delta_y;
	int		**color;
	float	zoom;
	float	zoom_z;
	int		decision_factor;
}	t_data;

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1920
# endif

# ifndef SCREEN_HIGHT
#  define SCREEN_HIGHT 1080
# endif

/*	color	*/

char		**save_color(char **s, t_data *img, int row);
char		**color_default(char **tmp, t_data	*img, int row, char *line);
void		save_hex_color(char *hexcolor, t_data	*img, int row, int col);
long int	decimal_value(char	*hexcolor);

/*	line	*/

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_x(t_data	*a, t_data	*b, t_data img, int color);
void		draw_y(t_data	*a, t_data	*b, t_data img, int color);
void		bresenham(t_data	*a, t_data	*b, t_data img, int color);

/*	reading map	*/

void		map_offset(t_data	*img);
void		free2d(char **s);
void		memory_allocation_and_check(t_data *img, int row);
void		read_map_subfunction(t_data *img, char *s, int fd);
void		read_map(char *name, t_data *img);

/*	draw	*/

void		print_keys(t_data	*img);
void		draw_sub_function2(t_data *a, t_data	*img, int i, int j);
void		draw_sub_function1(t_data *a, t_data *b, t_data *img);
void		draw_sub_function3(t_data *a, t_data *b, t_data *img);
void		draw(t_data *img);

/*	events	*/

void		move_map_helper(t_data *img);
void		zoom_map(int key_code, t_data *img);
void		move_map(int key_code, t_data *img);
void		rotate_map(int key_code, t_data *img);
int			key_hook(int key_code, t_data *img);

/*	events2	*/

void		redraw(t_data *img);

/*	errors	*/

void		errors(char *s, t_data	*img);
void		free_color(t_data	*img);
void		free_matrix(t_data	*img);
int			close_x(t_data *img);
void		error_exit(char	*s);

/*	main(fdf.c)		*/

int			ft_strlen_array(char	**s);
void		make_isometric(t_data	*img, t_data *main);
void		get_map_size(char	*name, t_data *img);
void		initialize_values(t_data *img);
int			main(int argc, char **argv);

/*	map_check	*/
void		validity_check(char *num);

#endif