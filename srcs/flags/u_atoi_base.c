/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_atoi_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:57:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 19:06:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"

static inline bool	add_isvalid(const u_char c, int8_t base, const char *valid) {
	while (base--)
		if (valid[base] == tolower(c))
			return true;
	return false;
}

static inline u_char	add_value_of(uint8_t c) {
	if (isdigit(c))
		return c - '0';
	else if (islower(c))
		return c - 'a' + 10;
	else if (isupper(c))
		return c - 'A' + 10;
	return 0;
}

int32_t	u_atoi_base(const char *str, int8_t base) {
	int32_t				num;
	int8_t				sign;
	const char *const	valid_hex = "0123456789abcdef";

	num = 0;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (add_isvalid(*str, base, valid_hex))
		num = num * base + add_value_of(*str++);
	return (num * sign);
}
