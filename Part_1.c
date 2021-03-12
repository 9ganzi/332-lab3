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
    else if (pid == 0)
    {
        printf("fork successful, child pid = %d\n\n", getpid());
        fflush(stdout); // buffer is not full yet, so you need this line to print the above

        execl("/bin/date", "date", NULL);
        printf("EXECL Failed\n");
    }

    wait(NULL);

    return 0;
}