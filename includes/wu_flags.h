/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:25:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 13:51:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_FLAGS_H
# define WU_FLAGS_H

# include "wu_algo_macroses.h"
# include "wu_algo_structs.h"

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

# define MAX_FLAGS  2
# define F_MLL      "--maxLineLength"
# define F_LC       "--linesCounter"

# define SF_MLL     "-mll"
# define SF_LC      "-lc"

# define DEF_MAX_LINE_LEN   WIN_X
# define DEF_LINES_COUNTER  10

# define MIN_LC		1
# define MIN_MLL	100

# define MAX_MLL	WIN_X
# define MAX_LC		100000

extern void	wu_init_flags_def_values(Flags *restrict const f);

bool	wu_flags_parser(Flags *restrict const f, char **av, const size_t ac);

typedef bool	(*fnptr_fparse)(Flags *restrict const, char**,
					const size_t, size_t *const);
extern bool		wu_f_mll(Flags *const f, char** av,
					const size_t ac, size_t *const av_i);
extern bool		wu_f_lc(Flags *const f, char** av,
					const size_t ac, size_t *const av_i);

bool	u_isalpha_str(const char *const str);
bool	u_isdigits_str(const char *const str);
bool	u_is_one_of_str(const char *const cmp,
						const bool cmp_len,
						size_t n, ...);

#endif
