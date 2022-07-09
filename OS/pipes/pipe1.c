#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


// Using pipes, find the sum of an array as follows:
//     - One process calculates the sum of half of the array and stores it in the pipe
//     - The second process calculates the sum of the other half, reads the sum on the pipe and returns the total sum.

int main()
{
    int arr[10] = {1, 2, 3, 4};
    int n = 4; 
    
    //CREATING THE PIPE
    int fd[2];
    int pipe_f = pipe(fd);
    
    if (pipe_f == -1)
    {
        printf("Pipe creation failed \n");
        return -1;
    }
    else if(pipe_f == 0)
    {
        printf("Pipe created successfully \n");
    }    

    pid_t pid; 
    pid = fork();
    
    if (pid > 0)
    {
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            sum += arr[i];
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        wait(NULL);
    }
     
    else if (pid == 0)
    {
        int sum_1st_half, sum_2nd_half = 0;
        read(fd[0], &sum_1st_half, sizeof(int));
        printf("Sum from the first process %d\n", sum_1st_half);
        for (int i = n/2; i < n; i++)
        {
            sum_2nd_half += arr[i];
        }
        printf("2nd half sum : %d \n", sum_2nd_half);
        printf("Total sum = %d\n", sum_2nd_half + sum_1st_half);
        close(fd[0]);
    }

    else
    {
        printf("Fork failed !! \n");
        return -1;
    }
    
    return 0;
}
