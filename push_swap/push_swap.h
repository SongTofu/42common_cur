/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:05:09 by song-yejin        #+#    #+#             */
/*   Updated: 2021/06/30 15:06:01 by yejsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# define RET_ERROR -1
# define RET_SUCCESS 1
# define RET_EOF 0
# define INF 72340172838076673
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct		s_list
{
	int				n;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	long long		num;
	long long		same_rotate;
	long long		a_rotate;
	long long		b_rotate;
	long long		tot;
}					t_info;

typedef struct		s_tmp
{
	t_list			*iter_a;
	t_list			*iter_b;
	int				a_sz;
	int				b_sz;
	int				idx_i;
	int				idx_j;
}					t_tmp;

void				ft_exit(char *s);
int					ft_isdigit(char c);
long long			ft_atoi(char **s, int sign);
void				ft_memset(char *dest, int size, char ch);
void				*ft_calloc(size_t number, size_t size, char ch);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				lower(char **line);
void				ft_free(t_list **a, t_list **b);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(char *str);
void				*ft_memcpy(void *dest, const void *src, size_t count);
int					ft_strcmp(const char *str1, const char *str2);
void				ft_append(char **line, char c);
void				move_stack(t_list **lst, int move);
int					ft_swap(t_list **lst);
int					ft_push(t_list **dest, t_list **src, char c);
int					ft_rotate(t_list **lst);
int					ft_r_rotate(t_list **lst);
void				ft_printf(char *s);
void				oper_printf2(long long t, char *c);
void				oper_printf(t_info mv);
void				lst_analysis(t_tmp *t, t_list **a, t_list **b);
void				run(t_tmp *tt, t_info *mn, t_info *mx, t_list **b);
void				func(t_tmp *tt, int flag, t_info *tmp);
void				calc(t_info *t, int a, int b, int flag);
void				b_sort(t_list **b, int size);
int					ag_parsing(t_list **lst, char *ag, int sz);
int					ags_get(int ac, char *ag[], t_list **lst);
int					make_node(int idx, t_list **lst);
void				dup_ck(t_list *lst_a);
void				oper_run(t_list **a, t_list **b);
void				oper_ck(char *line, t_list **a, t_list **b);
int					oper_ck2(char *line, t_list **a, t_list **b);
int					oper_ck3(char *line, t_list **a, t_list **b);
int					is_sort(t_list **lst);
void				push_swap_init(t_tmp *t, t_list **a, t_list **b);
#endif
