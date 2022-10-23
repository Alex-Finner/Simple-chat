#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main()
{
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sa, ca, sa2;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(0);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    int len = sizeof(struct sockaddr_in);
    int br = bind(net_socket, (struct sockaddr *)&sa, len);
    if (br > 0)
    {
        perror("error!!!");
    }

    getsockname(net_socket, (struct sockaddr *)&sa2, &len);
    printf("Port:%d\n IP ADDRESS:%s\n ", ntohs(sa2.sin_port), inet_ntoa(sa2.sin_addr));
    int lr = listen(net_socket, 10);
    if (lr > 0)
    {
        perror("error");
    }
    int fd;
    char data[200];
    char data2[200];
    int n;
    int x,n2;
    len = sizeof(struct sockaddr_in);
    while (1)
    {
        fd = accept(net_socket, (struct sockaddr *)&ca, &len);
        while (1)
        {
            /* code */
            read(fd,&x,sizeof(int));
            printf("recived :%d",x);
            printf("Enter:");
            scanf("%d", &n2);
            write(fd,&n2,sizeof(int));
        }
        close(fd);
    }
    close(net_socket);
    return 0;
}
