/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:25:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/08 13:24:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_FLAGS_H
# define WU_FLAGS_H

# include "wu_algo_macroses.h"
# include "wu_algo_structs.h"

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

# define MAX_FLAGS  5
# define F_MLL      "--maxLineLength"
# define F_LC       "--linesCounter"
# define F_BGC      "--backgroundColor"
# define F_FGC      "--foregroundColor"
# define F_HELP     "--help"

# define SF_MLL     "-mll"
# define SF_LC      "-lc"
# define SF_BGC     "-bgc"
# define SF_FGC     "-fgc"
# define SF_HELP    "-h"

# define DEF_MAX_LINE_LEN   WIN_X
# define DEF_LINES_COUNTER  10

# define MIN_LC		1
# define MIN_MLL	25

# define MAX_LC		1500000
# define MAX_MLL	WIN_X

extern void	wu_init_flags_def_values(Flags *restrict const f);

bool	wu_flags_parser(Flags *restrict const f, char **av, const size_t ac);

typedef bool	(*fnptr_fparse)(Flags *restrict const, char**,
					const size_t, size_t *const);
extern bool		f_help(Flags *restrict const f, char **av,
					const size_t ac, size_t *const av_i);
extern bool		f_mll(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i);
extern bool		f_lc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i);
extern bool		f_bgc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i);
extern bool		f_fgc(Flags *restrict const f, char** av,
					const size_t ac, size_t *const av_i);

// Flags utils\helper funcs:
bool	u_isalpha_str(const char *const str);
bool	u_isdigits_str(const char *const str);
bool	u_is_one_of_str(const char *const cmp,
						const bool cmp_len,
						size_t n, ...);
bool	u_ishex_str(const char *str);
int32_t	u_atoi_base(const char *str, int8_t base);

#endif
