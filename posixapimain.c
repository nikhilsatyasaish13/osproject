#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>

#define BLOCK_SIZE 4096
#define size 512

int main(int agrc, char** agrv)
{
  char inputFile[50], outputFile[50];
  int inputTest = -1;
  int outputTest = -1;
  int fd;
  ssize_t bytes_read = -1, bytes_write;
  char buffer[512];

  printf("Please input the name of the source file : \n");          // ?????????
  scanf("%s",inputFile);

  if ( (inputTest = open(inputFile , O_RDONLY)) == -1)              // ???????,??????
  {
    perror("Open file failed\n");
    exit(1);
  }    

  printf("Please input the name of the destination file : \n");     // ?????????
  scanf("%s",outputFile);

  outputTest = open(outputFile, O_CREAT | O_WRONLY, 0644);          // ???????,??????
  if (outputTest == -1)
  {
    perror("Open file failed\n");
    return 1;
  }

  while ((fd = read(inputTest,buffer,size)) > 0)                    // ?512???????,??????????,??????????????,?????????(??????) 
  {
    write(outputTest,buffer,fd);
  }

  close(inputTest);
  close(outputTest);
  
  return 0;
}