#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

 int main(int argc, char *argv[]){
  if(argc != 2){
   fprintf(stderr , "Usage: mycat <filename>\n");
   return 1;
  }
  int fd = open(argv[1], O_RDONLY);
  if(fd == -1){
   perror("mycat");
   return 1;
  }
  char buffer[1024];
  ssize_t bytes_read;
  while ((bytes_read = read(fd, buffer ,sizeof(buffer))) > 0){
   if(write(STDOUT_FILENO, buffer, bytes_read)==-1){ 
    perror("mycat: write");
    close(fd);
    return 1;
   }
  }
  if(bytes_read == -1){
   perror("mycat: read");
   close(fd);
   return 1;
  }
  close (fd);
  return 0;
 }



