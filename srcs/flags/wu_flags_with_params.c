/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:57:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 16:49:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"
#include "wu_algo_macroses.h"

inline bool		wu_f_mll(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	size_t	i = ~0UL;

	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
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
	return (true);
}

inline bool		wu_f_lc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i) {
	size_t	i = ~0UL;

	IF_VAMSG(ac <= ++*av_i, false,
		"ERROR: Missed param for: %s.\n", av[*av_i - 1]);
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
	return (true);
}
