/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:19:13 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/19 11:58:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_err				g_err[] = {\
	{LEM_SMALLPOP_ERR, "Lem-in Population must be at least `1`"},\
	{LEM_NOPOP_ERR, "Can't find the Population size"},\
	{LEM_MALLOC_ERR, "Memory allocation occured"},\
	{LEM_ROOM_FMT_ERR, "The room's format must be: `Room_name X_poition Y_position`"},\
	{LEM_DUPLICATE_ROOM_ERR, "Two rooms can't have the same name"},\
	{LEM_HALL_FMT_ERR, "The hall's format must be: `Room_name_1-Room_name_2`"},\
	{LEM_CYCLE_HALL_ERR, "Can't have the same room's name on both side of an hall"},\
	{LEM_UNKNOW_ROOM_ERR, "This room's name doesn't exist on the room's description"},\
	{LEM_DUPLICATE_HALL_ERR, "Can't have the same hall description more than once"},\
	{LEM_LINE_FMT_ERR, "Unknow line format. A line must be: a population size (N), a comment (#comment), a command (##command), a room description (string N N) or an hall description (string-string)"}\
};

t_lemcmd			g_cmd[] = {\
	{LEM_START_CMD, LEM_START_STATE},\
	{LEM_END_CMD, LEM_END_STATE},\
	{NULL, 0}\
};
