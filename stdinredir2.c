#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define CLOSE_DUP

int main()
{
    int fd,newfd;
    char line[100];

    fgets(line,100,stdin);
    printf("%s",line);
    
    fgets(line,100,stdin);
    printf("%s",line);
    
    fgets(line,100,stdin);
    printf("%s",line);
    
    fd=open("/etc/passwd",O_RDONLY);
    
#ifdef CLOSE_DUP
    close(0);
    newfd=dup(fd);
    printf("%d\n",newfd);
#else
    newfd=dup2(fd,0);
#endif
    if(newfd!=0){
        fprintf(stderr,"Could not duplicate fd to 0\n");
        exit(1);
    }
    close(fd);
    fgets(line,100,stdin);
    printf("%s",line);
    
    fgets(line,100,stdin);
    printf("%s",line);
    
    fgets(line,100,stdin);
    printf("%s",line);
    
}
