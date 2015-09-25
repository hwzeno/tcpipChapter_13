/*********************************
    > File Name: peek_send.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月24日 星期四 11时53分48秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);

}
int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in send_adr;
	if(argc != 3)
	{
		printf("Usage: %s <IP>, <port>\n", argv[0]);
		exit(1);
	}


	sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&send_adr, 0, sizeof(send_adr));
	send_adr.sin_family = AF_INET;
	send_adr.sin_addr.s_addr = inet_addr((argv[1]));
	send_adr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&send_adr, sizeof(send_adr)) == -1)
	{
		error_handling("connect() error1");
	}

	write(sock, "123", strlen("123"));
	close(sock);
	return 0;
}
