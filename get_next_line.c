/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:31:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/01/06 19:09:55 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define BUFFER_SIZE 1024

void	freethis(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(char *str, int var)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*str)
		return (NULL);
	if (var)
	{
		while (str[i] != '\n' && str[i])
			i++;
		tmp = ft_substr(str, 0, i + 1);
		return (tmp);
	}
	else
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
			i += 1;
		tmp = ft_substr(str, i, ft_strlen(str));
		return (tmp);
	}
	return (NULL);
}

char	*magic(char *str, int fd)
{
	int			c;
	char		*tmp;
	char		*tmp2;
	static char	*line;

	c = 1;
	if (line == NULL)
		line = ft_strdup("");
	while (checknl(line))
	{
		c = read(fd, str, BUFFER_SIZE);
		if (c <= 0)
			break ;
		str[c] = '\0';
		tmp = line;
		line = ft_strjoin(line, str);
		freethis(tmp);
	}
	tmp2 = line;
	tmp = get_line(tmp2, 1);
	line = get_line(tmp2, 0);
	freethis(tmp2);
	freethis(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	str = magic(str, fd);
	return (str);
}

// int main(int argc, char **argv)
// {
// 	int file;
// 	int i = 1;

// 	file = open("41_with_nl", O_RDONLY);
// 	while (i < 15)
// 	{
// 	 	printf("%d: %s\n", i, get_next_line(file));
// 		i++;
// 	}
// 	system("leaks a.out");
// 	return (0);
//  }