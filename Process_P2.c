#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    char buffer[100];
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("destination1.txt", O_WRONLY);
    int fd3 = open("destination2.txt", O_WRONLY);

    if ((fd1 == -1) || (fd2 == -1) || (fd3 == -1))
        fprintf(stderr, "open failed");

    int count = -1;

    while (count != 0)
    {
        count = read(fd1, buffer, 50);
        write(fd2, buffer, count);
        count = read(fd1, buffer, 100);
        write(fd3, buffer, count);
    }
    close(fd1);
    close(fd2);
    return 0;
}