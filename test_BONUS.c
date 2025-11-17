#include "get_next_line_bonus.h"


int main()
{
 /* int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file3.txt", O_RDONLY);
    int fd3 = open("file4.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    char *l1;
    char *l2;
    char *l3;

    printf("\n----- START TEST (BONUS) -----\n\n");

    while (1)
    {
        l1 = get_next_line(fd1);
        l2 = get_next_line(fd2);
        l3 = get_next_line(fd3);

        if (!l1 && !l2 && !l3)
            break;

        if (l1)
        {
            printf("FILE 1: %s", l1);
            free(l1);
        }
        if (l2)
        {
            printf("FILE 2: %s", l2);
            free(l2);
        }
        if (l3)
        {
            printf("FILE 3: %s", l3);
            free(l3);
        }
        printf("---------------------------\n");
    }

    printf("\n----- END TEST -----\n");

    close(fd1);
    close(fd2);
    close(fd3);
*/
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
    
 /* int fd1 = open("file1.txt",O_CREAT ,0666);
  
  char *buff2 = get_next_line(fd1);
  char *buff3 = get_next_line(fd1);
  char *buff4 = get_next_line(fd1);
  char *buff5 = get_next_line(fd1);
 printf("\nfile 2\n");
  printf("%s",buff2);
  printf("%s",buff3);
  printf("%s",buff4);
  printf("%s",buff5);*/
  

    //close(fd);
    //close(fd1);
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