/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nome.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:40:23 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 01:30:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NONE_H
# define NONE_H

typedef enum		s_otyp
{
	NO_OP,
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MOD,
	OP_EQ
}					t_otyp;

typedef struct		s_nome
{
	t_otyp			op;
	float			coef;
	float			exp;
}					t_nome;

#endif
