/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:14:18 by yejsong           #+#    #+#             */
/*   Updated: 2021/05/25 16:23:06 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define RET_ERROR -1
# define RET_SUCCESS 1
# define RET_EOF 0
# define MAP_COMPLETE 255
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT	17
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_ESC 53

typedef struct	s_info
{
	char		*cub_info[8];
	char		**map;
	int			win_x;
	int			win_y;
	int			height;
	int			width;
	int			player_x;
	int			player_y;
	int			f_rgb;
	int			c_rgb;
	int			save;
}				t_info;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_key
{
	int			a;
	int			w;
	int			s;
	int			d;
	int			esc;
}				t_key;

typedef struct	s_loca
{
	double		x;
	double		y;
}				t_loca;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_key		key;
	t_loca		sz_img[6];
	int			num_sprite;
	t_loca		*s;
	int			*sprite_o;
	double		*sprite_d;
	char		**map;
	int			win_x;
	int			win_y;
	int			height;
	int			width;
	int			f_rgb;
	int			c_rgb;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			**buf;
	int			**texture;
	double		*z_buffer;
	int			save;
}				t_game;

typedef struct	s_wcasting
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_s;
	int			draw_e;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_wcasting;

typedef struct	s_scasting
{
	double		sprite_x;
	double		sprite_y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			spritescreen_x;
	int			sprite_h;
	int			draw_s_y;
	int			draw_e_y;
	int			sprite_w;
	int			draw_s_x;
	int			draw_e_x;
}				t_scasting;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_atoi(char **s);
void			ft_free(char **line);
void			*ft_calloc(size_t number, size_t size, char ch);
int				ft_max(int x, int y);
int				ft_min(int x, int y);
int				ft_isspace(char c);
char			*ft_strchr(const char *str, int c);
void			ft_memset(char *dest, int size, char ch);
int				ft_strncmp(char *str1, char *str2, size_t n);
size_t			ft_strlen(char *str);
void			*ft_memcpy(void *dest, void *src, size_t count);
int				ft_append(char **line, char ch, char flag);
int				get_a_line(int fd, char **line, int flag);
int				info_parsing(char *line, t_info *info, int i);
int				cub_parsing(int fd, t_info *info);
void			make_map(char *line, t_info *info);
int				file_cker(char *filename, char *extension);
int				texture_ck(char *s, t_info *info, int i);
int				ft_valid(t_info *info);
int				contents_ck(t_info *info);
int				ag_ck(int ac, char *ag[]);
int				win_parsing(char *s, t_info *info, int inf);
int				rgb_parsing(char *s, t_info *info, int inf);
int				rgb2hex(int *tmp);
int				put_num(int *tmp, t_info *info, int inf);
int				map_ck(t_info *info, int player);
int				map_closed_ck(t_info *info);
int				dfs(int x, int y, t_info *info, int **visit);
void			wall_casting(t_game *g);
void			wall_init(int x, t_game *g, t_wcasting *tw);
void			dda(t_game *g, t_wcasting *tw);
void			get_height(t_game *g, t_wcasting *tw);
void			draw_one_line(int x, t_game *g, t_wcasting *tw);
void			sprite_casting(t_game *g);
void			sprite_init(t_game *g);
void			sprite_calc(t_game *g, t_scasting *ts, int i);
void			draw_sprites(t_game *g, t_scasting *ts, int color);
void			sort_sprites(int *order, double *dist, int n);
void			sort_order(t_pair *o, int n);
void			game_init(t_info *info, t_game *g);
void			player_init(t_info *i, t_game *g);
void			copy_map(t_info *info, t_game *g);
void			sprites_ck(t_info *info, t_game *g);
void			sprites_location(t_info *info, t_game *g);
void			set_header(unsigned char *header, int param);
void			bmp_test(t_game *g, int fd);
void			imgbmp(t_game *g, int fd, int color);
void			save_bmp(t_game *g);
int				main_loop(t_game *g);
void			calc(t_game *g);
void			floor_color(t_game *g);
void			draw(t_game *g);
void			key_update(t_game *g);
void			turn(t_game *g, double rot);
int				key_press(int key, t_game *g);
int				key_release(int key, t_game *g);
int				close_mouse();
void			ft_exit(char *s);
void			cub_init(int ac, char *ag[], t_info *info);
void			load_image(t_game *g, char *path, t_img *img, int i);
void			load_texture(t_info *info, t_game *g);
int				main(int ac, char *ag[3]);

#endif
