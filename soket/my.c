#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

static size_t	counter(char const *s, char c)
{
	size_t	counts;

	if (!s || !*s)
		return (0);
	counts = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counts++;
		while (*s != c && *s)
			s++;
	}
	return (counts);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	src = malloc(sizeof(*s) * (len + 1));
	if (src == NULL)
		return (NULL);
	while (len > size && s[i])
	{
		if (i >= start)
			src[size++] = s[i];
		i++;
	}
	src[size] = 0;
	return (src);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	lenss;
	int		i;

	str = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!strchr(s, c))
				lenss = strlen(s);
			else
				lenss = strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, lenss);
			s += lenss;
		}
	}
	str[i] = NULL;
	return (str);
}

void	free_strings(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char 	*get_domen(char *str)
{
	char **strs;
	char	*str_s;
	int	i = 0;
	strs = ft_split(str, '\n');
	while (strs[i] && strncmp("Buffer: GET /", strs[i], 13))
	{
		i++;
	}
	if (strs[i])
		printf("%s\n", strs[i]);
	str_s = ft_substr(strs[i], 14, strlen(strs[i]) - 13);
	free_strings(strs);
	return (str_s);
}


int	main(void)
{
	char *message = "Buffer: GET / HTTP/1.1\nHost: 127.0.0.1:8010\nConnection: keep-alive\nsec-ch-ua: \"Not A(Brand\";v=\"99\", \"Microsoft Edge\";v=\"121\", \"Chromium\";v=\"121\"\nsec-ch-ua-mobile: ?0\nsec-ch-ua-platform: \"Windows\"\nUpgrade-Insecure-Requests: 1\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\nSec-Fetch-Site: none\nSec-Fetch-Mode: navigate\nSec-Fetch-User: ?1\nSec-Fetch-Dest: document\nAccept-Encoding: gzip, deflate, br\nAccept-Language: en-US,en;q=0.9\n";
	char	*dom;

	dom = get_domen(message);
	printf("%s\n", dom);
	free(dom);
	return (0);
};
