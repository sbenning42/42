/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:02:07 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 15:14:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*payload_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_PAYLOAD_CFMT\
				: ASM_PAYLOAD_FMT));
}

char			*header_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_HEADER_CFMT\
				: ASM_HEADER_FMT));
}

char			*token_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_TOKEN_CFMT\
				: ASM_TOKEN_FMT));
}

char			*error_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_ERROR_CFMT\
				: ASM_ERROR_FMT));
}

char			*success_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_SUCCESS_CFMT\
				: ASM_SUCCESS_FMT));
}
