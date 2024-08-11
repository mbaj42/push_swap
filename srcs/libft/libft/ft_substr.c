/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:46:23 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 16:32:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	if (start > size)
		return (ft_strdup(""));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (size < start || sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char const k[] = "Ala ma kota";
	unsigned int st = 4;
	size_t	t = 10;
	
	printf("%s", ft_substr(k, st, t));
	return (0);
}*/
