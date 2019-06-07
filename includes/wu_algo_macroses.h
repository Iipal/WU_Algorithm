/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_macroses.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:30:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 23:42:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_MACROSES_H
# define WU_ALGO_MACROSES_H

# define WIN_TITLE "Xiaolin Wu's line algorithm"
# ifdef __APPLE__
#  define WIN_X 2000
#  define WIN_Y 1000
# elif defined __linux__
#  define WIN_X 1000
#  define WIN_Y 500
# else
#  warning "Unsupported OS. Try to compile this on MacOS or Linux."
#  define WIN_X 200
#  define WIN_Y 100
# endif

# include <sys/cdefs.h>
# ifndef __wu_always_inline
#  if defined __header_always_inline
#   define __wu_always_inline __header_always_inline
#  elif defined __always_inline
#   define __wu_always_inline __always_inline
#  else
#   define __wu_always_inline
#  endif
# endif

# define IF_MSG(exception, ret, message) {\
	if ((exception)) {\
		dprintf(STDERR_FILENO, message);\
		return (ret);} }
# define IF_VAMSG(exception, ret, message, ...) {\
	if ((exception)) {\
		dprintf(STDERR_FILENO, message, __VA_ARGS__);\
		return (ret);} }
# define IF(exception, ret) { if ((exception)) { return (ret);} }

# define IF_NOT_MSG(exception, ret, message) {\
	if (!(exception)) {\
		dprintf(STDERR_FILENO, message);\
		return (ret); } }
# define IF_NOT_VAMSG(exception, ret, message, ...) {\
	if (!(exception)) {\
		dprintf(STDERR_FILENO, message, __VA_ARGS__);\
		return (ret); } }
# define IF_NOT(exception, ret) { if (!(exception)) { return (ret); } }
# define IF_NOT_DO(exception, do, ret) {\
	if (!(exception)) { do; return (ret); } }

# define FREE(trash, fn_del) { if ((trash)) {fn_del((trash));} }

# define SWAP(a, b) { typeof(a) _a = (a); (a) = (b); (b) = _a; }

#endif
