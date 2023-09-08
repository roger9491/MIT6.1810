#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


void closeOtherFileDescriptors(int i, int p[35][2]) {
    for (int j = 0; j < 35; j++) {
        if (j!= i || j != i + 1) {
            close(p[j][0]);
            close(p[j][1]);
        }
    }
}

void main(int argc, char *argv[])
{
    int p[35][2];
    pipe(p[0]);
    for (int i = 2; i <= 13; i++)
    {
        pipe(p[i-1]);
        write(p[0][1], &i, 4);
        if (fork() == 0)
        {
            int number;
            int sendNumber;
            closeOtherFileDescriptors(i-2, p);
            read(p[i-2][0], &number, 4);
            printf("prime %d\n", number);
            while (1)
            {
                read(p[i-2][0], &sendNumber, 4);
                // printf("end : %d, number %d\n", i, sendNumber);
                if (sendNumber % number != 0)
                {
                    write(p[i-1][1], &sendNumber, 4);
                }else if (sendNumber == -1) {
                    printf("end : %d\n", i);
                    write(p[i-1][1], &sendNumber, 4);
                    exit(0);
                }
            }
        }
    }

    int end = -1;
    write(p[0][1], &end, 4);
    wait(0);
}



// void main(int argc, char *argv[])
// {
//     int p[34][2];
//     // for (int i = 2; i <= 4; i++)
//     // {
//     //     pipe(p[i - 2]);
//     //     write(p[0][1], &i, 4);
//     //     if (fork() == 0)
//     //     {
//     //         int sendNumber;
//     //         while (1)
//     //         {
//     //             read(p[i - 2][0], &sendNumber, 4);
//     //             if(i == 4) printf("prime %d\n", sendNumber);
//     //             if (sendNumber == 4)
//     //             {
//     //                 exit(0);
//     //             }
//     //             write(p[i - 1][1], &sendNumber, 4);
//     //         }
//     //     }
//     // }
//     int i;
//     pipe(p[0]);
//     pipe(p[1]);
//     if (fork() == 0)
//     {
//         int sendNumber;
//         while (1)
//         {
//             read(p[0][0], &sendNumber, 4);
//             printf("sendNumber %d", sendNumber);
//             write(p[1][1], &sendNumber, 4);
            
//         }
//     }
//     if (fork() == 0)
//     {
//         int sendNumber;
//         while (1)
//         {
//             read(p[1][0], &sendNumber, 4);
//            printf("sendNumber2 %d", sendNumber);
//         }
//     }
//     i = 1;
//     write(p[0][1], &i, 4);
//     i = 2;
//      write(p[0][1], &i, 4);

//     wait(0);

// }