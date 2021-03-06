/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:43:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/30 22:24:33 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*addr;
	void	*win;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		counter;
	int		collectibles_c;
	int		collected;
}		t_data;

typedef struct s_str
{
	char	*donut1;
	char	*donut2;
	char	*player;
	char	*enemy;
	char	*collectible;
	char	*exit;
	char	*border;
}	t_str;

char			*ft_strdup(char *src);
int				checknl(char *str);
char			*get_next_line(int fd);
void			freethis(void *ptr);
void			freethis1(char **str);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
size_t			ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
void			draw(char **map, t_data *data, t_str *paths);
int				key_hook(int key, void *ptr);
char			**move_up(t_data *data);
char			**move_down(t_data *data);
char			**move_right(t_data *data);
char			**move_left(t_data *data);
void			img_to_window (t_data *data, char *path);
int				animation(t_data *data);
void			rotate_donut(t_data *data, char *path);
char			**move_up_enemy(t_data *data);
char			**move_down_enemy(t_data *data);
char			**move_right_enemy(t_data *data);
char			**move_left_enemy(t_data *data);
int				*get_coordinates_enemy(t_data *data);
int				collectibles_counter(t_data *data);
int				game_over(t_data *data);
#endif