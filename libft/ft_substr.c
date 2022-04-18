/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:20:38 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/08 14:20:38 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	len_s;
	unsigned int	len_s_need;

	if (s == NULL)
		return (NULL);
	len_s = (unsigned int)ft_strlen((char *)s);
	len_s_need = (unsigned int)ft_strlen((char *)s + start);
	if (len_s < start)
		return (ft_strdup(""));
	if (len_s_need < len)
		len = len_s_need;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
