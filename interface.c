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
    char inputs[50];
    // make pipes
    mkfifo("pipeuno", 0644);
    int fd1 = open("pipeuno", O_WRONLY);
    mkfifo("pipedos", 0644);
    int fd2 = open("pipedos",O_RDONLY);

    // ask inputs and write & read for response
    while(strcmp("exit\n", inputs)){
      printf("Enter the word: \n");
      fgets(inputs,50,stdin);
      inputs[strlen(inputs)-1] = '\0';
      printf("You inputed: %s\n",inputs);
      write(fd1, inputs, 50);
      char result [50];
      read(fd2,result,50);
      printf("Response from worker: %s\n", result);
}

  return 0;
}
