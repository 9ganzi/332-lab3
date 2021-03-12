#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{

    pid_t pid1 = fork(); // fork a child

    if (pid1 < 0) // fork failed
    {
        fprintf(stderr, "Fork Failed\n");
        return 0;
    }
    else if (pid1 == 0) // child process 1
    {
        char *const argv[] = {NULL};
        execv("./Process_P1", argv);
        printf("EXECVP Failed\n");
    }
    else
    {
        wait(NULL); // parent wait for child process 1
        pid_t pid2 = fork(); // fork another child

        if (pid2 < 0) // fork failed
        {
            fprintf(stderr, "Fork Failed\n");
            return 0;
        }
        else if (pid2 == 0) // child process
        {
            char *const argv[] = {NULL};
            execv("./Process_P2", argv);
            printf("EXECVP Failed\n");
        }
    }

    wait(NULL); // parent wait for child process 2

    return 0;
}

/*
Write a C program and call it ​Parent_Process.c​. Execute the files as per the following procedure using
execv​ ​system call.

[Step 3] ​Fork a child process, say ​Child 1 ​and execute ​Process_P1​. This will create two destination files
according to Step 1.
[Step 4] ​After ​Child 1 ​finishes its execution, fork another child process, say ​Child 2 ​and execute
Process_P2 ​that accomplishes the procedure described in Step 2.
*/