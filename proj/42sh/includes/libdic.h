#ifndef LIBDIC_H
# define LIBDIC_H

# include "libft.h"

typedef struct			s_dic_test
{
	char				*user;
	char				*group;
	char				*shell;
	char				*home;
}						t_dic_test;

typedef struct			s_dic_entry
{
	void				*content;
	size_t				content_size;
	char				*key;
	struct s_dic_entry	*f;
	struct s_dic_entry	*l;
	struct s_dic_entry	*r;
}						t_dic_entry;

typedef int				(*t_dic_sort)(char *, char *);
typedef void			(*t_dic_del)(void *content);

int						dic_sort(char *k1, char *k2);
void					dic_del(void *content);

t_dic_entry				*ft_dicnew(char *key, void *content, size_t size);
void					ft_dicadd(t_dic_entry **dic, t_dic_entry *entry, \
						t_dic_sort sort);
void					ft_dicdump(t_dic_entry *dic, int fd);
void					ft_dicdumpc(t_dic_entry *dic, int asc);
void					*ft_dicget(t_dic_entry *dic, char *key);
void					ft_dicdel(t_dic_entry **dic, t_dic_del del);

#endif
