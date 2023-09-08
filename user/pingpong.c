#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(int argc, char *argv[])
{
    int p[2];
    pipe(p);

    char buffer;
    if (fork() == 0) {
        read(p[0], &buffer, 1);
        printf("%d: received ping\n", getpid());
        write(p[1], "b", 1);
    } else {
        write(p[1], "b", 1);
        read(p[0], &buffer, 1);
        printf("%d: received pong\n", getpid());
    }

    
}