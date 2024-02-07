#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define CONFIG_FILE "config.txt"
#define PORT 8080

typedef struct			s_dns_header
{
	unsigned short		id;
 
	unsigned char		rd :1;
	unsigned char		tc :1;
	unsigned char		aa :1;
	unsigned char		opcode :4;
	unsigned char		qr :1;

	unsigned char		rcode :4;
	unsigned char		z :3;
	unsigned char		ra :1;

	unsigned short		q_count;
	unsigned short		ans_count;
	unsigned short		auth_count;
	unsigned short		add_count;
}					t_dns_header;

int	is_print(char c)
{
	if (c <=32 && c <=126)
		return(1);
	return(0);
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

struct Config {
	char	upstream_server[16];
	char	blacklist[10][32];
	char	response[16];
};

void	read_config(const char *filename, struct Config *config)
{
	FILE	*file;
	char	line[256];
	char	*key;
	char	*value;
	int i;

	i = 0;

	printf("Reading configuration file\n");

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Failed to open configuration file");
		exit(1);
	}
	while (fgets(line, sizeof(line), file))
	{
		key = strtok(line, " ");
		value = strtok(NULL, " ");
		if (strcmp(key, "upstream_server:") == 0)
		{
			strcpy(config->upstream_server, value);
		}
		else if (strcmp(key, "blacklist:") == 0)
		{
			while ((strcmp(key, "upstream_server:") != 0) && (strcmp(key, "response") != 0) &&  value != NULL)
			{
				strcpy(config->blacklist[i], value);
				i++;
				value = strtok(NULL, " ");
			}
		}
		else if (strcmp(key, "response:") == 0)
			strcpy(config->response, value);
	}
	printf("Configuration file is read successfully\n");
	fclose(file);
}

int	get_soc(void)
{
	int						soc;
	int						enable;
	struct sockaddr_in		server;

	soc = socket(AF_INET, SOCK_DGRAM, 0);
	if (soc == -1)
	{
		perror("Error_socet\n");
		exit (1);
	}
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	server.sin_port = htons(PORT);

	enable = 1;
	if (setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) == -1)
	{
		printf("%d %d %d %d\n", soc, SOL_SOCKET, SO_REUSEADDR, enable);
		close(soc);
		perror("setsockopt");
		exit (1);
	}
	if (bind(soc, (struct sockaddr *)&server, sizeof(server)) == -1)
	{
		perror("bind\n");
		exit (1);
	}
	return (soc);
}

int	check_blacklist(char *domain, struct Config *config)
{
	int i;
	char	*str;
	char	*str2;

	i = 0;
	str = ft_substr(domain, 1, strlen(domain));
	str2 = str;
	while (*str2)
	{
		if (!is_print(*str2))
			str2 = ".";
		str2++;
	}
	
	while (i < 4)
	{
		if (strcmp(str, config->blacklist[i]) == 0)
		{
			printf("Blacklisted domain: %s\n", str);
			printf("%s\n", config->blacklist[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	refused_send(struct Config *conf, int soc, char *buffer, int recive_b, struct sockaddr_in *client)
{
	t_dns_header 				*dns_h;
	socklen_t 					clnt_adrs_len;
	int							send_byte;

	clnt_adrs_len = sizeof(*client);

	dns_h = (t_dns_header *)buffer;
	dns_h->qr = 1;
	dns_h->rcode = 5;
	dns_h->ans_count = 0;

	if (sendto(soc,  buffer, recive_b, 0, (struct sockaddr *)client, sizeof(client)) == -1)
	{
		printf("sendto\n");
		exit(1);
	}
}

int	resend(struct Config *conf, char *buffer, int recivee_b)
{
	int		new_soc;
	struct sockaddr_in dest;
	socklen_t	dest_size;

	new_soc = socket(AF_INET, SOCK_DGRAM, 0);
	if (new_soc == -1)
	{
		printf("sock\n");
		exit(1);
	}
	dest_size = sizeof(dest);
	bzero(&dest, dest_size);
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(conf->upstream_server);
	dest.sin_port = htons(53);

	if (sendto(new_soc, buffer, recivee_b, 0, (struct sockaddr *)&dest, dest_size) == -1)
	{
		printf("sendto last\n");
		exit(1);
	}
	recivee_b = recvfrom(new_soc, buffer, 1024, 0, (struct sockaddr*)&dest, &dest_size);
	if (recivee_b < 0)
	{
		printf("recvfrom last\n");
		exit(1);
	}
	if (close(new_soc) == -1)
	{
		printf("recvfrom last\n");
		exit(1);
	}
	return (recivee_b);
}

void	ansver_ask(struct Config *conf, int soc)
{
	int		recive_b;
	int		n;
	int		send_b;
	char	*domen;
	char	buffer[1024];
	struct	sockaddr_in	client;
	socklen_t	size_client;
	pid_t	pid;

	size_client = sizeof(client);

	while (42)
	{
		bzero(buffer, 1024);

		recive_b = recvfrom(soc, buffer, 1024, 0, (struct sockaddr*)&client, &size_client);
		if (recive_b < 0)
		{
			printf("recvfrom start\n");
			exit (1);
		}
		pid = fork();
		if (pid == -1)
		{
			printf("fork\n");
			exit (1);
		}
		if (pid == 0)
		{
			if (check_blacklist(&buffer[12], conf) == 1)
				refused_send(conf, soc, buffer, recive_b, &client);
			else
			{
				n = resend(conf, buffer, recive_b);
				send_b = sendto(soc, buffer, n, 0, (struct sockaddr *)&client, size_client);
				if (send_b < 0)
				{
					printf("send to loop\n");
					exit(1);
				}
			}
			close(soc);
			exit(0);
		}
	}
	
}

void	print_conf(struct Config *conf)
{
	printf("responce: %s\n", conf->response);
	printf("upstream_server: %s\n", conf->upstream_server);
	for (int i = 0; i < 5; i++)
	{
		printf("black_list: %s\n", conf->blacklist[i]);
	}
}

int main(void)
{
	int				soc;
	struct Config	config;


	soc = get_soc();
	read_config(CONFIG_FILE, &config);
	print_conf(&config);
	ansver_ask(&config, soc);
	return (0);
}
