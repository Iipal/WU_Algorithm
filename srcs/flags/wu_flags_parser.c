/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:23:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 16:51:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"

static bool	add_parse_current_flag(Flags *restrict const f,
	char **av, const size_t ac, size_t *const av_i) {
	const char			*flags[] = {F_MLL, F_LC};
	const char			*sflags[] = {SF_MLL, SF_LC};
	const fnptr_fparse	fns[] = {wu_f_mll, wu_f_lc};
	bool				is_valid_flag = false;
	size_t				i = ~0UL;

	while (MAX_FLAGS > ++i)
		if (u_is_one_of_str(av[*av_i], false, 2, flags[i], sflags[i])) {
			is_valid_flag = true;
			return (fns[i](f, av, ac, av_i));
		}
	if (!is_valid_flag) {
		dprintf(STDERR_FILENO,
			"ERROR: Invalid flag: %s.\n", av[*av_i]);
		return (false);
	}
	return (is_valid_flag);
}

bool	wu_flags_parser(Flags *restrict const f, char **av, const size_t ac) {
	size_t	i = ~0UL;

	while (ac > ++i)
		if ('-' == av[i][0]
		&& (('-' == av[i][1] && u_isalpha_str(av[i] + 2))
		|| u_isalpha_str(av[i] + 1))) {
			if (!add_parse_current_flag(f, av, ac, &i))
				return (false);
		} else {
			dprintf(STDERR_FILENO,
				"ERROR: Invalid flag semantics: %s.\n", av[i]);
			return (false);
		}
	return (true);
}
