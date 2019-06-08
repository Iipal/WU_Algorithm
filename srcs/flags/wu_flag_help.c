/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flag_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:23:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/08 13:43:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"

inline bool		f_help(Flags *restrict const f, char **av,
					const size_t ac, size_t *const av_i) {
	(void)f; (void)av; (void)ac; (void)av_i;
	printf( "Flags usage:\n"
	"  -h, --help: Print this mesage.\n"
	"  -mll, --maxLineLneght: Set max random line lenght. Default: %d.\n"
	"  -lc, --linesCounter: Set how much lines will randomize. Default: %d.\n"
	"  -fgc, --foregroundColor: Set foreground(lines) color. Default: %#x.\n"
	"  -bgc, --backgroundColor: Set background color. Default: 0x0.\n",
	DEF_MAX_LINE_LEN, DEF_LINES_COUNTER, 0xffffff);
	return (false);
}
