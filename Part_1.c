#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // fork a child

    if (pid < 0) // when forking is failed
    {
        fprintf(stderr, "Fork Failed\n");
        return 0;
    }
    else if (pid == 0) // child process
    {
        printf("fork successful, child pid = %d\n\n", getpid());
        fflush(stdout); // buffer is not full yet, so you need this line to print the above

        execl("/bin/date", "date", NULL);
        printf("EXECL Failed\n"); // the program will reach this line only if execl function fails
    }

    wait(NULL); // wait for child process

    return 0;
}