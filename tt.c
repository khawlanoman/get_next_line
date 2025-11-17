/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:11:11 by khnoman           #+#    #+#             */
/*   Updated: 2025/11/04 11:11:13 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char *read_file(int fd, char *stash)
{
   ssize_t  read_byte;
   char *buffer;

   read_byte = 1;
   buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
   if (!buffer)
      return (NULL);
   if (fd == -1)
     return (NULL);
   while (!ft_strchr(stash, '\n') && read_byte > 0)
   {
      read_byte = read(fd, buffer, BUFFER_SIZE);
      if (read_byte < 0)
      {
            free(stash);
            free (buffer);
            return (NULL);
      }
      buffer[read_byte] = '\0';
      stash = ft_strjoin(stash, buffer);
      if (!stash)
         return (NULL);
   }
   free(buffer);
   return (stash);
}
static char *set_line(char *line)
{
   ssize_t  i;
   ssize_t j;
   char *line_c;

   j = 0;
   i = 0;
   if (line[0] =='\0')
      return (NULL);
   while (line[i] && line[i] !='\n')
      i++;
   if (line[i] == '\n')
      line_c = malloc((i + 2) * sizeof(char));
   else
      line_c  = malloc((i + 1) * sizeof(char));
   if (!line_c)
      return (NULL);
   while (j <= i && line[j])
   {
      line_c[j] = line[j];
      j++;
   }
   line_c[j] = '\0';
   return(line_c);

}

static char *extract_line(char *line)
{
   ssize_t i;
   char *left;

   i = 0;
   while (line[i] && line[i] !='\n')
      i++;
   if (!line[i])
   {
     free(line);
     return (NULL);
   }
   if (line[i] == '\n')
      i++;
   left = ft_substr(line, i, ft_strlen(line) - i);
  
   if (!left)  
   {
      free(line);
      return NULL;
   }
   free(line);
   return (NULL);
}

char *get_next_line(int fd)
{
    static char    *stash;
    char   *line;

    if (fd < 0 || BUFFER_SIZE <= 0 )
      return (NULL);
   stash = read_file(fd,stash);
   if (!stash)
      return (NULL);
   line = set_line(stash);
   stash = extract_line(stash);
   return (line);
}
