#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t pid = fork(); // forking a child

    if (pid < 0) // fork failed
    {
        fprintf(stderr, "Fork Failed\n");
        return 0;
    }
    else if (pid == 0) // chidl process
    {
        char *const argv[] = {"ls", "-la", NULL};
        execvp("ls", argv); // execute ls -la
        printf ("EXECVP Failed\n");
    }

    wait(NULL); // wait for child process
    printf("\nfork successful, child pid = %d\n", pid);

    return 0;
}