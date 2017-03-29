/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:15:10 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 16:57:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regexp.h"

void dump_lexem(t_regex_lexem *lst)
{
	while (lst)
	{
		ft_printf("\t%s: `%s`\n", lst->parser_key, lst->value);
		lst = lst->next;
	}
}

typedef struct s_ttest t_ttest;

struct		s_ttest
{
	char	*str;
	int		ref;
};

typedef struct s_test t_test;

struct		s_test
{
	char	*str;
	int		ref;
	t_ttest tests[128];
};

struct s_test	g_tests[] = {\
	{"a", 1, {{"a", 1}, {"b", 0}, {NULL, -1}}},\
	{"abc", 1, {{"abc", 1}, {"abd", 0}, {NULL, -1}}},\
	{"abc?", 1, {{"abc", 1}, {"", 1}, {NULL, -1}}},\
	{"[a-z]*", 1, {{"def", 1}, {"d0f", 0}, {NULL, -1}}},\
	{"-?[0-9]+", 1, {{"42", 1}, {"-42", 1}, {"-42t", 0}, {NULL, -1}}},\
	{"[A-Z][a-z]*", 1, {{"Toto", 1}, {"TOto", 0}, {NULL, -1}}},\
	{"[a-z]0", 1, {{"a0", 1}, {"0", 0}, {NULL, -1}}},\
	{"*", 0, {{NULL, -1}}},\
	{"[a]", 0, {{NULL, -1}}},\
	{"[a-*]", 0, {{NULL, -1}}},\
	{NULL, -1, {{NULL, -1}}}\
};

int		main(void)
{
	int		ret;
	int		ref;
	int		i = -1;
	int		j = -1;
	char	*tmp;
	t_regex_lexem	*lst;

	while (g_tests[++i].str)
	{
		tmp = g_tests[i].str;
		ref = g_tests[i].ref;
		lst = NULL;

		ret = parse(REGEXP_ALL, &tmp, (void *)&lst);
		
		ft_printf("Test %d: (%d | %d)%{%s} --> %{%s}\n",\
				i, ref, ret, tmp, g_tests[i].str);

		dump_lexem(lst);

		j = -1;
		while (g_tests[i].tests[++j].str)
		{
			tmp = g_tests[i].tests[j].str;
			ref = g_tests[i].tests[j].ref;
			
			ret = reg_match(lst, tmp);

			ft_printf("\tTest %d: (%d | %d) --> %{%s}\n",\
					j, ref, ret, tmp);
		}

	}
	return (0);
}
