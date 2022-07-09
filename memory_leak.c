#include <stdlib.h>
#include <stdio.h>
int main(void)
{ 
    char *line = NULL;
    size_t size = 0;
    //The loop below leaks memory as fast as it can 
    for(;;) { 
        getline(&line, &size, stdin); 
       
        line = NULL;
    }
  // the allocated  memory is not freed hence memory leak takes place
    return 0;
 }
