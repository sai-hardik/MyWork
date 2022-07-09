#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2 ,p3 ,p4;

    int y = 0;

    p1 = fork();
    p2 = fork();

    if (p1 > 0 && p2 > 0) //parent process
    {
        wait(NULL);

        y = y - 1;

        printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);

        execl("/bin/tty", "/home/hardik/Desktop/PES2UG20CS296/OS/LAB_5", NULL);
    }
    else if (p1 == 0 && p2==0) // child process 
    {
        p3 = fork();
       

        if (p3> 0 && p4>0)
        {
           wait(NULL);
        }
/*        else if (p2 == 0)
        {
           y = y + 5;
           
           printf("This is grandchild. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);

           execl("/bin/ls", "/home/hardik/Desktop/PES2UG20CS296/OS/LAB_2/prog_5", "-r", NULL);

           exit(0);
        }*/

        y = y + 1;

        printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n", getpid(), getppid(), y);

 execl("/bin/tty", "/home/hardik/Desktop/PES2UG20CS296/OS/LAB_5", NULL);
        char *a[] = {NULL};

        execv("/home/hardik/Desktop/PES2UG20CS296/OS/LAB_5", a);

        exit(0);
    }
    else //fork failed
    {
        printf("\n");
    }
}
