/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:31 by yass              #+#    #+#             */
/*   Updated: 2023/11/30 19:47:21 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cara;
	unsigned char		char_c;

	i = 0;
	cara = (const unsigned char *)s;
	char_c = (unsigned char)c;
	while (i < n)
	{
		if (cara[i] == char_c)
			return ((void *)(cara + i));
		i++;
	}
	return (NULL);
}
