/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:34:44 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/05 15:08:13 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*final;
	final = (char *)s;
	while (*final)
	{
		// printf("----------HERE-----------\n");
		if (*final == c)
			return (final);
		final++;
	}
	// printf("final = *%s*\n", final);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	count;	

	if (!len || (size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s + start)) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc((len + 1) * sizeof(ptr));
	if (!ptr)
		return (NULL);
	count = 0;
	while (count < len)
	{
		ptr[count] = s[(size_t)start + count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	ptr = (char *) malloc(len * sizeof(ptr));
	i = 0;
	while (i < len - 1)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_linecount(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\n')
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(len * sizeof(ptr));
	if (ptr == 0)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		i++;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
