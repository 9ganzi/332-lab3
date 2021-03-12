#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed\n");
        return 0;
    }
    else if (pid == 0)
    {
        char *const argv[] = {"ls", "-la", NULL};
        execvp("ls", argv); // execute ls -la
        printf ("EXECVP Failed\n");
    }

    wait(NULL);
    printf("\nfork successful, child pid = %d\n", pid);

    return 0;
}