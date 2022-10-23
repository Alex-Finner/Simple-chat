#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main(int argc, char *argv[])
{
    int l_socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    struct sockaddr_in sa,ca;
    sa.sin_family=AF_INET;
    sa.sin_port=htons(atoi(argv[2]));
    sa.sin_addr.s_addr=inet_addr(argv[1]);
    int cr=connect(l_socket,(struct sockaddr*)&sa,sizeof(ca));
    char data[200];
    char dat2[200];
    int n;
    int n2;
    int x;
    while (1)
    {
        printf("\n Enter:");
        scanf("%d",&x);
        write(l_socket,&x,sizeof(int));
        n=read(l_socket,&n2,sizeof(int));
        printf("recived :%d\n",n2);
    }
    close(l_socket);
    
    return 0;
}
