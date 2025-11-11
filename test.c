#include "get_next_line.h"

int main()
{
    int fd = open("file.txt",O_RDWR | O_CREAT |O_APPEND,0666);
    
    char *buff = get_next_line(fd);
    char *buff1 = get_next_line(fd);
    char *buff2 = get_next_line(fd);
    printf("%s",buff);
    printf("%s",buff1);
    printf("%s",buff2);

    close(fd);
    
      /*int fd;
  
    fd =open("T1.txt",O_WRONLY |O_APPEND | O_CREAT,0666);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    
    write(fd,"noman",5);
   
    printf("%d",fd)*/
    return 0;
}