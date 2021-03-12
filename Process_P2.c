#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    char buffer[100];
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("destination1.txt", O_WRONLY);
    int fd3 = open("destination2.txt", O_WRONLY);

    if ((fd1 == -1) || (fd2 == -1) || (fd3 == -1)) // when any of the open system call failes
        fprintf(stderr, "open failed");

    int count = -1;

    while (count != 0)
    {
        count = read(fd1, buffer, 50); // read 50 characters
        write(fd2, buffer, count); // write those 50 characters to the destination1.txt
        count = read(fd1, buffer, 100); // read 100 characters
        write(fd3, buffer, count); // write those 100 characters to the destination2.txt
    }
    close(fd1);
    close(fd2);
    return 0;
}