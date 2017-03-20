/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:19:13 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 12:29:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_err				g_err[] = {\
	{LEM_SMALLPOP_ERR, LEM_SMALLPOP_MSG},\
	{LEM_NOPOP_ERR, LEM_NOPOP_MSG},\
	{LEM_MALLOC_ERR, LEM_MALLOC_MSG},\
	{LEM_ROOM_FMT_ERR, LEM_ROOM_FMT_MSG},\
	{LEM_DUPLICATE_ROOM_ERR, LEM_DUPLICATE_ROOM_MSG},\
	{LEM_HALL_FMT_ERR, LEM_HALL_FMT_MSG},\
	{LEM_CYCLE_HALL_ERR, LEM_CYCLE_HALL_MSG},\
	{LEM_UNKNOW_ROOM_ERR, LEM_UNKNOW_ROOM_MSG},\
	{LEM_DUPLICATE_HALL_ERR, LEM_DUPLICATE_HALL_MSG},\
	{LEM_LINE_FMT_ERR, LEM_LINE_FMT_MSG},\
	{LEM_LOGIC_ERR, LEM_LOGIC_MSG},\
	{0, NULL}\
};

t_lemcmd			g_cmd[] = {\
	{LEM_START_CMD, LEM_START_STATE},\
	{LEM_END_CMD, LEM_END_STATE},\
	{NULL, 0}\
};
