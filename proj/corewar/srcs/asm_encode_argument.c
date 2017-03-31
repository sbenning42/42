/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_encode_argument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:20:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 14:04:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		encode_direct_slabel(t_instruction *ins, t_payload *payload, unsigned int i, t_label *label)
{
	short	val;
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(short) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (short)(label->offset - ins->offset);
	val = SHORT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(short));
	ins->arg_size += sizeof(short);
	return (0);
	(void)payload;
	(void)i;
}

int		encode_direct_ilabel(t_instruction *ins, t_payload *payload, unsigned int i, t_label *label)
{
	int				val;
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(int) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (int)(label->offset - ins->offset);
	val = INT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(int));
	ins->arg_size += sizeof(int);
	return (0);
	(void)i;
	(void)payload;
}

void label_error(char *label)
{
	ft_fprintf(2, "Can't find this label: %s\n", label);
}

int		encode_direct_label(t_instruction *ins, t_payload *payload, unsigned int i)
{
	t_label	*label;

	if (!(label = get_label(payload->labels, ins->str_arguments[i] + 2)))
	{
		label_error(ins->str_arguments[i]);
		return (-1);
	}
	if (ins->op->label_size == 2)
		return (encode_direct_slabel(ins, payload, i, label));
	return (encode_direct_ilabel(ins, payload, i, label));
	(void)payload;
}

int		encode_direct_value(t_instruction *ins, t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;
	short			sval;
	int				ival;
	size_t			size;

	size = ins->op->label_size;
	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(size + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	if (size == 2)
	{
		sval = SHORT_BIG2LITTLE((short)ft_atoi(ins->str_arguments[i] + 1));
	}
	else if (size == 4)
	{
		ival = INT_BIG2LITTLE((int)ft_atoi(ins->str_arguments[i] + 1));
	}
	ft_memcpy(ins->arg_payload + ins->arg_size, (size == 2 ? (void *)&sval : (void *)&ival), size);
	ins->arg_size += size;
	return (0);
	(void)payload;
}

int		encode_indirect(t_instruction *ins, t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;
	short			val;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(short) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (short)ft_atoi(ins->str_arguments[i]);
	val = SHORT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(short));
	ins->arg_size += sizeof(short);
	return (0);
	(void)payload;
}

int		encode_registre(t_instruction *ins, t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(unsigned char) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	ins->arg_payload[ins->arg_size] = (unsigned char)ft_atoi(ins->str_arguments[i] + 1);
	ins->arg_size += sizeof(unsigned char);
	return (0);
	(void)payload;
}
