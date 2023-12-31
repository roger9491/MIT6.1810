#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"



/**
 * @brief 
 * 
 * @param path 
 * @return file or dir name 
 */
char *fmtname(char *path)
{
    static char buf[DIRSIZ + 1];
    char *p;

    // Find first character after last slash.
    for (p = path + strlen(path); p >= path && *p != '/'; p--)
        ;
    p++;

    // Return blank-padded name.
    if (strlen(p) >= DIRSIZ)
        return p;
    memmove(buf, p, strlen(p));
    memset(buf + strlen(p), ' ', DIRSIZ - strlen(p));
    return buf;
}

void find(char *path, char *filename){
    char buf[512], *p;
    int fd;
    struct dirent de;
    struct stat st;    
    if ((fd = open(path, 0)) < 0){
        fprintf(2, "ls: cannot open %s\n", path);
        return;
    }
    if (fstat(fd, &st) < 0){
        fprintf(2, "ls: cannot stat %s\n", path);
        close(fd);
        return;
    }

    switch (st.type){
        case T_DEVICE:
        case T_FILE:
            if (strcmp(fmtname(path), filename) == 0) {
                printf("%s %d %d %l\n", fmtname(path));
            }  
            break;
        case T_DIR:
            if (strlen(path) + 1 + DIRSIZ + 1 > sizeof buf)
            {
                printf("ls: path too long\n");
                break;
            }
            strcpy(buf, path);
            p = buf + strlen(buf);
            *p++ = '/';

            // print current directory path
            while (read(fd, &de, sizeof(de)) == sizeof(de))
            {
                if (de.inum == 0)
                    continue;
                memmove(p, de.name, DIRSIZ);
                p[DIRSIZ] = 0;
                if (stat(buf, &st) < 0)
                {
                    printf("ls: cannot stat %s\n", buf);
                    continue;
                }
                printf("%s\n", buf);
            }
            break;
        }
    close(fd);
}
// todo: Completed stringJoin, Compose a recursive directory search

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        fprintf(2, "usage: find pattern {}\n");
        exit(1);
    }
    find(argv[1], argv[2]);
    exit(0);
}

