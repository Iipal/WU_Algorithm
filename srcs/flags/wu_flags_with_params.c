/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:57:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 09:53:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"
#include "wu_algo_utils.h"

inline bool		f_mll(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	size_t	i = ~0UL;

	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
	IF_VAMSG(f->is_mll, true,
		"WARNING: You already use %s flag before. This[%s] value will be ignored.\n", av[*av_i - 1], av[*av_i]);
	while (av[*av_i][++i])
		if (isblank(av[*av_i][i]))
			++av[*av_i];
	IF_VAMSG('-' == av[*av_i][0], false,
		"ERROR: Only unsigned values for: %s flag.\n", av[*av_i - 1]);
	IF_NOT_VAMSG(u_isdigits_str(av[*av_i]), false,
		"ERROR: Only digits in params for %s flag.\n", av[*av_i - 1]);
	f->max_line_lenghts = atoi(av[*av_i]);
	IF_VAMSG(MAX_MLL < f->max_line_lenghts, false,
		"ERROR: (%s [for: \'%s\']) cannot be bigger than %d. Max is %d.\n",
		av[*av_i], av[*av_i - 1], MAX_MLL, MAX_MLL);
	IF_VAMSG(MIN_MLL > f->max_line_lenghts, false,
		"ERROR: (%s [for: \'%s\']) cannot be less than %d. Min is %d.\n",
		av[*av_i], av[*av_i - 1], MIN_MLL, MIN_MLL);
	return f->is_mll = true;
}

inline bool		f_lc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	size_t	i = ~0UL;

	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
	IF_VAMSG(f->is_lc, true,
		"WARNING: You already use %s flag before. This[%s] value will be ignored.\n", av[*av_i - 1], av[*av_i]);
	while (av[*av_i][++i])
		if (isblank(av[*av_i][i]))
			++av[*av_i];
	IF_VAMSG('-' == av[*av_i][0], false,
		"ERROR: Only unsigned values for: %s flag.\n", av[*av_i - 1]);
	IF_NOT_VAMSG(u_isdigits_str(av[*av_i]), false,
		"ERROR: Only digits in params for %s flag.\n", av[*av_i - 1]);
	f->lines_counter = atoi(av[*av_i]);
	IF_VAMSG(MAX_LC < f->lines_counter, false,
		"ERROR: (%s [for: \'%s\']) cannot be bigger than %d. Max is %d.\n",
		av[*av_i], av[*av_i - 1], MAX_LC, MAX_LC);
	IF_VAMSG(MIN_LC > f->lines_counter, false,
		"ERROR: (%s [for: \'%s\']) cannot be less than %d. Min is %d.\n",
		av[*av_i], av[*av_i - 1], MIN_LC, MIN_LC);
	return f->is_lc = true;
}

inline bool		f_bgc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	(void)f;
	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
	IF_VAMSG(g_is_bgc, true,
		"WARNING: You already use %s flag before. This[%s] value will be ignored.\n", av[*av_i - 1], av[*av_i]);
	IF_VAMSG(strncmp("0x", av[*av_i], strlen("0x")), false,
		"ERROR: Missed \'0x\' prefix for color for: %s flag.\n", av[*av_i - 1]);
	av[*av_i] += 2;
	IF_VAMSG(strlen(av[*av_i]) > 6, false,
		"ERROR: Invalid hex[0x%s] number for: %s. Valid is \'0xRRGGBB\'.\n",
		av[*av_i], av[*av_i - 1]);
	IF_NOT_VAMSG(u_ishex_str(av[*av_i]), false,
		"ERROR: Invalid hex[0x%s] number for: %s.\n", av[*av_i], av[*av_i - 1]);
	g_bg_clr.hex = u_atoi_base(av[*av_i], 16);
	IF_VAMSG(!g_bg_clr.hex, false,
		"ERROR: Something went wrong or param[0x%s] is 0x0(depricated) for: %s flag.\n", av[*av_i], av[*av_i - 1]);
	return g_is_bgc = true;
}

inline bool		f_fgc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	(void)f;
	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
	IF_VAMSG(g_is_fgc, true,
		"WARNING: You already use %s flag before. This[%s] value will be ignored.\n", av[*av_i - 1], av[*av_i]);
	IF_VAMSG(strncmp("0x", av[*av_i], strlen("0x")), false,
		"ERROR: Missed \'0x\' prefix for color for: %s flag.\n", av[*av_i - 1]);
	av[*av_i] += 2;
	IF_VAMSG(strlen(av[*av_i]) > 6, false,
		"ERROR: Invalid hex[0x%s] number for: %s. Valid is \'0xRRGGBB\'.\n",
		av[*av_i], av[*av_i - 1]);
	IF_NOT_VAMSG(u_ishex_str(av[*av_i]), false,
		"ERROR: Invalid hex[0x%s] number for: %s.\n", av[*av_i], av[*av_i - 1]);
	g_fg_clr.hex = u_atoi_base(av[*av_i], 16);
	IF_VAMSG(!g_fg_clr.hex, false,
		"ERROR: Something went wrong or param[0x%s] is 0x0(depricated) for: %s flag.\n", av[*av_i], av[*av_i - 1]);
	return g_is_fgc = true;
}
