#include "../pipex.h"

size_t	ft_strlen(const char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
		iter++;
	return (iter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		iter;
	size_t	length;

	iter = 0;
	length = ft_strlen((char *)src);
	if (!dstsize)
		return (length);
	while (dstsize - 1)
	{
		dst[iter] = src[iter];
		if (!dst[iter] || !src[iter])
			return (length);
		iter++;
		dstsize--;
	}
	dst[iter] = '\0';
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_lenght;
	size_t	s2_lenght;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_lenght = ft_strlen(s1);
	s2_lenght = ft_strlen(s2);
	result = malloc((s1_lenght + s2_lenght + 1) * sizeof(char));
	printf("(ft_strjoin) allocated memory: %p\n", result);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, s1_lenght + 1);
	ft_strlcpy(result + s1_lenght, s2, s2_lenght + 1);
	return (result);
}
