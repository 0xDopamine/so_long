/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:42:14 by mbaioumy          #+#    #+#             */
/*   Updated: 2021/11/27 15:34:53 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*cat(char *dest, char const *s, int pos)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dest[pos] = s[i];
		pos++;
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	total;
	int		i;
	int		j;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	tab = (char *)malloc(sizeof(char) * total + 1);
	if (!tab)
		return (NULL);
	tab = cat(tab, s1, 0);
	tab = cat(tab, s2, ft_strlen(s1));
	return (tab);
}

/*int	main()
{
	char *str = "Hello";
	char sep[] = "1234";
	printf("%s", ft_strjoin(str, sep));
	return 0;
}*/
