#include "get_next_line.h"

int main()
{

    int fd = open("file1.txt", O_RDONLY);
      char *buff = get_next_line(fd);
  char *buff1 = get_next_line(fd);
  char *buff2 = get_next_line(fd);
  printf("%s",buff);
  printf("%s",buff1);
  printf("%s\n",buff2);
  free(buff);
  free(buff1);
  free(buff2);
    close(fd);

//////////////////
printf("\n");
int fd2 = open("file4.txt", O_RDONLY | O_CREAT);
  char *buf = get_next_line(fd2);
 char *buf1 = get_next_line(fd2);

  printf("%s",buf);
printf("%s",buf1);
  free(buf);
  free(buf1);
  close(fd2);

/////////////
  int fd3 = open("file3.txt", O_RDONLY | O_CREAT);
  char *bu = get_next_line(fd3);
 char *bu1 = get_next_line(fd3);
 char *bu2 = get_next_line(fd3);
  printf("%s",bu);
  printf("%s",bu1);
  printf("%s",bu2);
  free(bu);
  free(bu1);
  free(bu2);
    close(fd3);
   
 /*int fd = open("file.txt", O_RDONLY);
   char *line = get_next_line(fd);

    if (fd < 0)
        return (1);

    while (line)
    {
        printf("%s", line);
        free(line);
	line = get_next_line(fd);
    }

    free(line);
    */

 /* char *buff = get_next_line(fd);
  char *buff1 = get_next_line(fd);
  char *buff2 = get_next_line(fd);
  printf("%s",buff);
  printf("%s",buff1);
  printf("%s",buff2);
  free(buff);
  free(buff1);
  free(buff2);
    close(fd);*/
    
   /*int fd = open("file.txt", O_RDWR);
    char *line;

    if (fd < 0)
        return (1);

    while (line == get_next_line(fd))
    {
        printf("%s", line);
        free(line);
	
    }
  close(fd);*/
  //char buffer[50];
 // int fd = open("file.txt", O_RDWR);

 // int r = read(fd, buffer, 10);
  //write(fd, buffer, 10);
   //char *s = malloc(10);
   //s = malloc(20);
 //s = "hello";
  /* s[0] = 'H';
   s[1] = 'H';
   s[2] = 'H';
   s[3] = 'H';
   s[4] = 'H';
   s[5] = 'H';
   s[6] = 'H';
   s[7] = '\0';
  free(s);*/
  //    int fd = open("file.txt",O_RDWR | O_CREAT |O_APPEND,0666);
    
  // char *buff = get_next_line(fd);
  // char *buff1 = get_next_line(fd);
  // char *buff2 = get_next_line(fd);
  // printf("%s",buff);
  // printf("%s",buff1);
  // printf("%s",buff2);
  //   close(fd);
    
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
