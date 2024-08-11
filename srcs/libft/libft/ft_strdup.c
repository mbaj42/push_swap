/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:44 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 16:32:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*h;
	size_t	i;

	i = 0;
	h = (char *)s;
	d = (char *)malloc((ft_strlen(h) + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/*
int	main(void)
{
	char	k[] = "Antof4lk";
	printf("%s", ft_strdup(k));
	return (0);
}*/	
