/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:16:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 13:17:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"
#include "wu_flags.h"

static inline void	add_init_flags_def_values(Flags *restrict const f)
{
	*f = (Flags){DEF_MAX_LINE_LEN};
}

int		main(int argc, char *argv[])
{
	Environment	*env;

	--argc;
	++argv;
	IF_NOT_VAMSG(env = (Environment*)malloc(sizeof(Environment)), 0,
		"Can't allocate %zu bytes memory for `env` aka `Environment*`",
		sizeof(Environment));
	add_init_flags_def_values(&env->flags);
	if (argc && !wu_flags_parser(&env->flags, argv, argc))
		return (1);
	IF_NOT_DO(sdl_init(&env->sdl, WIN_TITLE, WIN_X, WIN_Y), wu_free(env), 0);
	wu_randomatic_lines_pos(env->line_starts, env->line_ends,
							env->flags.max_line_lenghts);
	sdl_render_loop(env);
	wu_free(env);
}
