#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>

using namespace std;

int main()
{
    pid_t pid;
    char a[1024];
    int One[2];
    int Two[2];
    pipe(One);
    if (pipe(One)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    pipe(Two);
    if (pipe(Two)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }
    pid = fork();
     if (pid < 0) 
    { 
        fprintf(stderr, "Fork Failed" ); 
        return 1; 
    } 
    if (pid > 0) 
    {
       
        int i;
        close(One[1]); 
        read(One[0], a, sizeof(a));
        for(i = 0; i<sizeof(a); i++) {
            if(islower(a[i]))
                a[i] = toupper(a[i]);
            else
                a[i] = tolower(a[i]);
        }
        write(Two[1], a, strlen(a) + 1);
        wait(NULL); 
    }else if (pid == 0){
        
		close(One[0]); 
        
		printf("input: ");
        fgets(a, sizeof(a), stdin);
        printf("The original message is %s",a);
        write(One[1], a, strlen(a) + 1);
        read(Two[0],a, sizeof(a));
        printf("The inverted message is %s",a);
        exit(0);
    }

    return 0;
}
