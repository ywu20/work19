#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/wait.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main (){
  int fd1 = open("pipeuno", O_RDONLY);

  int fd2 = open("pipedos",O_WRONLY);


    char inputs[50];

    //printf("Reead : %d\n", read(fds[READ], inputs, sizeof(inputs)));
    while (read(fd1, inputs, 50)){

    printf("Worker got: %s \n", inputs);
    char response[50];
    int i;
    for(i=0;i<50;i++){
      response[i] = toupper(inputs[i]);
    }
    int a= write(fd2, response, 50);
    //printf("wrote %d bytes\n", a);
   }

close(fd1);
close(fd2);

  return 0;
}
