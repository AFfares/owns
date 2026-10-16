#include <stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
 if (argc != 2){
  fprintf(stderr, "Usage: mymkdir <directory\n");
  return 1;
 }
 if (mkdir(argv[1], 0755) == -1){
  perror("mymkdir");
  return 1;
 }
 return
 0;
}
