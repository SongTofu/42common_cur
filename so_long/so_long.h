/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:37:06 by song-yejin        #+#    #+#             */
/*   Updated: 2021/11/02 17:05:55 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define RET_ERROR -1
# define RET_SUCCESS 1
# define RET_EOF 0
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT	17
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_ESC 53
# define TILE_SIZE	64

typedef struct s_pos	t_pos;
typedef struct s_lst	t_lst;
typedef struct s_img	t_img;
typedef struct s_ber	t_ber;
typedef struct s_game	t_game;

struct		s_pos
{
	int				x;
	int				y;
};

struct	s_lst
{
	t_pos			p;
	int				eat;
	struct s_lst	*n;
};

struct		s_img
{
	void			*ptr;
	int				*data;
	int				h;
	int				w;
	int				endian;
	int				bpp;
	int				size_l;
};

struct		s_ber
{
	int				height;
	int				width;
	char			**map;
	t_pos			player;
	t_lst			*exit;
	t_lst			*collect;
	int				c_count;
	int				p_count;
	int				e_count;
};

struct		s_game
{
	void			*mlx;
	void			*win;
	t_img			img[5];
	t_ber			b;
	int				walk;
	t_img			monitor;
	int				finish;
};

int		main_loop(t_game *g);
void	draw_map(t_game *g);
void	draw_etc(t_game *g);
void	draw(t_game *g, int x, int y, t_img tex);
void	is_finish(t_game *g);
void	eat_collect(t_game *g, int x, int y);
void	move(t_game *g, int i, int j);
int		key_press(int key, t_game *g);
int		close_mouse(void);
int		ft_append(char **line, char ch);
int		get_a_line(int fd, char **line);
void	ft_exit(char *s);
void	ft_free(char **line);
int		ft_max(int x, int y);
void	*ft_calloc(size_t number, size_t size, char ch);
size_t	ft_strlen(char *str);
void	ft_memset(char *dest, int size, char ch);
int		ft_strncmp(char *str1, char *str2, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t count);
char	*ft_strchr(const char *str, int c);
int		map_valid(t_ber *ber);
void	contents_ck(t_ber *ber);
void	num_ck(char c, char flag, t_ber *ber, t_pos here);
void	map_rec_ck(t_ber *ber);
void	map_closed_ck(t_ber *ber);
void	av_ck(int ac, char **av);
int		file_cker(char *filename, char *extension);
void	file_read(char *filename, t_ber *ber);
int		ber_parsing(int fd, t_ber *ber);
void	make_map(char *line, t_ber *ber);
t_lst	*lst_new(int x, int y);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst **lst, t_lst *new);
void	lst_clear(t_lst *head);
void	good_bye(t_game *g, char *s);
void	texture_init(t_game *g);
int		main(int ac, char **av);

#endif