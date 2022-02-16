/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:51:22 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 14:59:48 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include <math.h>

# define MAX_FD 10240
# define BUFFER_SIZE 10000
# define WHITE 0xFFFFFF
# define W_WIDTH 1280
# define W_LENGTH 720

# define ON_KEYDOWN 2

# define ESC_KEY 53
# define A_KEY 0
# define S_KEY 1
# define Q_KEY 12
# define W_KEY 13
# define Z_KEY 6
# define X_KEY 7
# define F_KEY 3
# define G_KEY 5
# define P_KEY 35
# define I_KEY 34
# define SP_KEY 49
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define PL_KEY 24
# define MN_KEY 27

typedef struct s_draw_line
{
	int		x;
	int		y;
	int		p;
}				t_draw_line;

typedef struct s_2d
{
	int		x;
	int		y;
	int		scale;
	int		scale_z;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		proj;
}				t_2d;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_new_line
{
	t_point	pp;
	int		dx;
	int		dy;
	int		p;
	int		n;
}				t_new_line;

typedef struct s_map
{
	int		x;
	int		y;
	int		color;
}			t_map;

typedef struct s_array
{
	t_point	**map;
	int		w;
	int		l;
}				t_array;

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}				t_line;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_array	array;
	t_map	**proj;
	t_2d	move;
	int		nb_img;
	int		offset_x;
	int		offset_y;
}				t_vars;

//gnl functions

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_free(char **val);

//list_utils.c

void	ft_create_list(t_line **list, char *path);
void	ft_line_error(int fd, t_line **line);
void	ft_print_list(t_line *list);
void	ft_free_list(t_line **list);
int		ft_list_size(t_line *list);

//general_utils.c

int		ft_atoi(char *str);
char	*ft_strchr(char *str, char c);
int		ft_hex_color(char *str);
t_line	*ft_read_line(int fd);

//conversion_utils

t_point	**ft_create_array(t_line **lst, int *width, int *lenght);
int		ft_get_lenght(char *str, char c);
t_point	*ft_create_line(char *str, int width, int y);
void	ft_free_grid(t_point **array, int length);

//conversion_utils_2.c

int		ft_get_z(char **str, int *color);
void	ft_get_z_helper(char **str, int *ret, int *color);
void	ft_get_z_helper_2(char **str, int *ret, int *color, char **sub);

//print_helpers

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_point	ft_scale(t_point point, t_vars vars);
void	ft_find_offset(t_vars *vars);
void	ft_modify_offset(t_vars *vars);
void	ft_find_margins(t_vars *vars);

//window_helpers.c

void	ft_modify_array(t_array array, int angle, int size);
int		ft_print_map(int key_code, t_vars *vars);
void	ft_print_new(t_vars *vars);
void	ft_print_vertical(t_vars *vars);
void	ft_print_horizontal(t_vars *vars);

// draw_line_helpers.c

void	ft_draw_line(t_vars *vars, t_map p1, t_map p2);
void	ft_draw_line_high(t_vars *vars, t_map p1, t_map p2);
void	ft_draw_line_low(t_vars *vars, t_map p1, t_map p2);
void	ft_draw_low(t_new_line *point, t_map p1, t_map p2, t_vars *vars);
void	ft_draw_high(t_new_line *point, t_map p1, t_map p2, t_vars *vars);

//draw_line_helpers2.c

double	ft_percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		ft_get_color(t_map p1, t_map p2, t_point current);

//rotate_utils.c

void	ft_rotate_z(t_vars vars, t_point *point);
void	ft_rotate_x(t_vars vars, t_point *point);
void	ft_rotate_y(t_vars vars, t_point *point);

int		ft_check_point(t_map p1, t_map *new_p);

//helper_functions.c

void	ft_init_isometric(t_vars *vars);
void	ft_free_isometric(t_vars *vars);
void	ft_fill_isometric(t_vars *vars);
void	ft_isometric(t_vars *vars);
void	ft_paralel(t_vars *vars);

//decide_helpers.c

void	ft_scale_map(int key, t_vars *vars);
void	ft_move_map(int k, t_vars *vars);
void	ft_rotate_map(int k, t_vars *vars);
void	ft_flat_and_proj(int k, t_vars *vars);

//display_helpers.c

void	ft_usage_window(t_vars vars);
void	ft_print_detalis(t_vars vars);
void	ft_print_details_2(t_vars vars);

//libft_utils.c

char	*ft_itoa(int n);
int		len_nb(int n);
char	*put_nb(char *str, int n, int len);

#endif