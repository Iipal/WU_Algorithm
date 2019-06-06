/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:16:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 22:07:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"
#include "wu_flags.h"

__wu_always_inline bool
add_allocate_lines(Environment *restrict const env) {
	env->line_starts =
		(__v2df*)malloc(sizeof(__v2df) * env->flags.lines_counter);
	IF_NOT_VAMSG(env->line_starts, false,
		"Can't allocate %zu bytes of memory for `env->line_start`"
		"aka `__v2df*`", sizeof(__v2df) * env->flags.lines_counter);
	env->line_ends = (__v2df*)malloc(sizeof(__v2df) * env->flags.lines_counter);
	IF_NOT_VAMSG(env->line_ends, false,
		"Can't allocate %zu bytes of memory for `env->line_ends`"
		"aka `__v2df*`", sizeof(__v2df) * env->flags.lines_counter);
	return true;
}

int		main(int argc, char *argv[]) {
	Environment	*env;

	--argc;
	++argv;
	IF_NOT_VAMSG(env = (Environment*)malloc(sizeof(Environment)), 0,
		"Can't allocate %zu bytes of memory for `env` aka `Environment*`",
		sizeof(Environment));
	bzero(env, sizeof(Environment));
	g_bg_clr = CLR_BLACK;
	g_fg_clr = CLR_WHITE;
	wu_init_flags_def_values(&env->flags);
	IF_NOT_DO(wu_flags_parser(&env->flags, argv, argc), wu_free(env), 0);
	IF_NOT_DO(sdl_init(&env->sdl, WIN_TITLE, WIN_X, WIN_Y), wu_free(env), 0);
	IF_NOT_DO(add_allocate_lines(env), wu_free(env), 0);
	wu_randomatize_lines_pos(env->line_starts, env->line_ends,
		env->flags.max_line_lenghts, env->flags.lines_counter);
	sdl_render_loop(env);
	wu_free(env);
}
