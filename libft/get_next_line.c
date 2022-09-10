/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:31:54 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/08/23 16:28:38 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst = malloc(1 * sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	i = 0;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < (unsigned int)len && s[i + start])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_updatebuf(char *buffer)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup(buffer);
	if (ft_strchr(buffer, '\n'))
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		ft_strcpy(buffer, &copy[i + 1]);
	}
	if (!ft_strchr(copy, '\n'))
	{
		if (copy)
			free(copy);
		ft_bzero(buffer, MAXSIZE);
		return (buffer);
	}	
	if (copy)
		free(copy);
	return (buffer);
}

char	*ft_leftstr(char *buf, ssize_t *counter)
{
	char	*ptr;
	char	*leftstr;
	size_t	i;

	i = *counter;
	leftstr = NULL;
	while (i < MAXSIZE)
	{
		buf[i] = '\0';
		i++;
	}
	ptr = ft_strchr(buf, '\n');
	if (ptr)
		leftstr = ft_substr(buf, 0, ft_strlen(buf) - ft_strlen(ptr) + 1);
	else
		return (ft_strdup(buf));
	return (leftstr);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		buf2[MAXSIZE];
	char			*line;
	ssize_t			n;
	static ssize_t	counter = 0;

	line = NULL;
	if (fd < 0 || fd > FDMAX || BUFFER_SIZE <= 0)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	n = 1;
	while (!ft_strchr(buf2, '\n') && n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (0);
		counter = counter + n;
		if (n)
			ft_strcat(buf2, buf);
	}
	if ((n == 0 && !buf[0]) && !buf2[0])
		return (0);
	line = ft_leftstr(buf2, &counter);
	ft_updatebuf(buf2);
	return (line);
}
